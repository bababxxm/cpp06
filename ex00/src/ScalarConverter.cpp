/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 20:39:18 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/22 00:51:16 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return (*this);
}

ScalarConverter::~ScalarConverter(void) {}

static bool isChar(const std::string& str) {
	return (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]));
}

static bool isPseudo(const std::string& str) {
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" ||
	        str == "-inff");
}

static void printChar(double d, bool impossible) {
	std::cout << "char: ";
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

static std::string formatNumber(double val) {
	if (val == std::numeric_limits<double>::infinity()) { return ("+inf"); }

	std::ostringstream oss;
	oss << val;
	std::string s = oss.str();

	if (s.find("nan") == std::string::npos && s.find("inf") == std::string::npos &&
	    s.find('.') == std::string::npos && s.find('e') == std::string::npos) {
		s += ".0";
	}
	return (s);
}

static void printFloat(double d, bool impossible) {
	std::cout << "float: ";
	if (impossible) {
		std::cout << "impossible";
	} else {
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

	if (isPseudo(str)) {
		dVal = std::strtod(str.c_str(), NULL);
	} else if (isChar(str)) {
		dVal = static_cast<double>(str[0]);
	} else {
		dVal = std::strtod(str.c_str(), &end);
		if (str.empty() || end == str.c_str() || (*end != '\0' && *end != 'f')) {
			impossible = true;
		} else if (*end == 'f' && *(end + 1) != '\0') {
			impossible = true;
		}
	}

	printChar(dVal, impossible);
	printInt(dVal, impossible);
	printFloat(dVal, impossible);
	printDouble(dVal, impossible);
}
