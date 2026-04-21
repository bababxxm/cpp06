/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 20:39:18 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/21 18:00:11 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

static bool isChar(const std::string& str) {
	return (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]));
}

static bool isPseudo(const std::string& str) {
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" ||
	        str == "-inff");
}

static void printChar(double d, bool impossible) {
	std::cout << "char: ";
	// Check for NaN (d != d), overflow, or impossible flag
	if (impossible || d != d || d < 0 || d > 127) {
		std::cout << "impossible";
	} else if (!std::isprint(static_cast<char>(d))) {
		std::cout << "Non displayable";
	} else {
		std::cout << "'" << static_cast<char>(d) << "'";
	}
	std::cout << std::endl;
}

static void printInt(double d, bool impossible) {
	std::cout << "int: ";
	if (impossible || d != d || d < std::numeric_limits<int>::min() ||
	    d > std::numeric_limits<int>::max()) {
		std::cout << "impossible";
	} else {
		std::cout << static_cast<int>(d);
	}
	std::cout << std::endl;
}

// Helper to handle the ".0" formatting logic for Float/Double
static std::string formatNumber(double val) {
	// 1. Handle positive infinity manually to ensure '+' is printed
	if (val == std::numeric_limits<double>::infinity()) { return ("+inf"); }

	std::ostringstream oss;
	oss << val;
	std::string s = oss.str();

	// If it looks like an integer (no dot, no scientific 'e', not inf/nan)
	if (s != "inf" && s != "-inf" && s != "nan" && s.find('.') == std::string::npos &&
	    s.find('e') == std::string::npos) {
		s += ".0";
	}
	return (s);
}

static void printFloat(double d, bool impossible) {
	std::cout << "float: ";
	if (impossible) {
		std::cout << "impossible";
	} else {
		// Cast to float first to get correct precision/overflow behavior for float
		// type
		float f = static_cast<float>(d);
		std::cout << formatNumber(f) << "f";
	}
	std::cout << std::endl;
}

static void printDouble(double d, bool impossible) {
	std::cout << "double: ";
	if (impossible) {
		std::cout << "impossible";
	} else {
		std::cout << formatNumber(d);
	}
	std::cout << std::endl;
}

void ScalarConverter::convert(const std::string& str) {
	char* end;
	double dVal = 0.0;
	bool impossible = false;

	// 1. Detect Special Cases (Pseudo Literals)
	if (isPseudo(str)) {
		// strtod handles "nan"/"inf" correctly, but we need to ensure we don't
		// mark it as "garbage" later.
		dVal = std::strtod(str.c_str(), NULL);
	}
	// 2. Detect Char Literal
	else if (isChar(str)) {
		dVal = static_cast<double>(str[0]);
	}
	// 3. Detect Number (Float/Double/Int)
	else {
		dVal = std::strtod(str.c_str(), &end);

		// Validation:
		// 1. If str is empty
		// 2. If strtod consumed NOTHING (end == str.c_str()) -> Catches "f", "abc",
		// etc.
		// 3. Garbage at end that isn't 'f'
		// 4. 'f' at end but not just "f" (handled by checking *end == 'f')
		if (str.empty() || end == str.c_str() || (*end != '\0' && *end != 'f')) {
			impossible = true;
		}
		// Specific check for things like "123ff"
		else if (*end == 'f' && *(end + 1) != '\0') {
			impossible = true;
		}
	}

	// 4. Output Results using Helpers
	printChar(dVal, impossible);
	printInt(dVal, impossible);
	printFloat(dVal, impossible);
	printDouble(dVal, impossible);
}
