/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:02:37 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/21 17:55:53 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "ScalarConverter.hpp"

#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

#define BOLD "\033[1m"
#define B_BLACK "\033[1;30m"
#define B_RED "\033[1;31m"
#define B_GREEN "\033[1;32m"
#define B_YELLOW "\033[1;33m"
#define B_BLUE "\033[1;34m"
#define B_MAGENTA "\033[1;35m"
#define B_CYAN "\033[1;36m"
#define B_WHITE "\033[1;37m"

#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

#define UNDERLINE "\033[4m"
#define REVERSED "\033[7m"  // Swaps foreground and background
#define DIM "\033[2m"       // Faint text, great for separators
#define ITALIC "\033[3m"    // (Support varies by terminal)

template <typename T>
std::string paint(const char* color, T value) {
	std::stringstream ss;
	ss << color << value << RESET;
	return ss.str();
}

void test_header(std::string title) {
	std::cout << "\n" << paint(B_CYAN, "[" + title + "]") << std::endl;
}

void test_convert(std::string input) {
	std::cout << paint(B_YELLOW, "Input: \"" + input + "\"") << std::endl;
	ScalarConverter::convert(input);
	std::cout << paint(DIM, "----------------------------------------") << std::endl;
}

int main(int argc, char** argv) {
	if (argc > 1) {
		ScalarConverter::convert(argv[1]);
		return 0;
	}

	std::cout << "Running tests..." << std::endl;

	test_header("TEST 1: Char Literals");
	test_convert("c");
	test_convert("a");
	test_convert("48");  // Should detect as int 0 first, but display char '0'
	test_convert("*");

	test_header("TEST 2: Integer Literals");
	test_convert("42");
	test_convert("-42");
	test_convert("0");
	test_convert("2147483647");   // INT_MAX
	test_convert("-2147483648");  // INT_MIN

	test_header("TEST 3: Float/Double Literals");
	test_convert("42.0");
	test_convert("42.0f");
	test_convert("4.2");
	test_convert("4.2f");
	test_convert("-42.42");
	test_convert("-42.42f");

	test_header("TEST 4: Pseudo Literals (Special)");
	test_convert("nan");
	test_convert("nanf");
	test_convert("+inf");
	test_convert("+inff");
	test_convert("-inf");
	test_convert("-inff");

	test_header("TEST 5: Edge Cases & Overflows");
	test_convert("2147483648");  // Overflow Int Max (should print int: impossible)
	test_convert("1.5e5");       // Double precision scientific notation
	test_convert("0.0005f");     // Small float

	test_header("TEST 6: Invalid / Impossible Inputs");
	test_convert("128");
	test_convert("hello");
	test_convert("42abc");   // Mixed garbage
	test_convert("42.0ff");  // Too many f's
	test_convert("..42");    // Multiple dots
	test_convert("");        // Empty string
	test_convert("f");       // Tricky one (should be impossible, not 0.0)

	std::cout << "All tests are finished..." << std::endl;

	return 0;
}
