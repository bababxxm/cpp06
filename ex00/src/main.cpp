/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 22:02:37 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/09 04:45:18 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

void test_header(std::string title) {
  std::cout << "\n"
            << "\033[1;36m[ " << title << " ]\033[0m" << std::endl;
}

void convert(std::string input) {
  std::cout << "\033[1;33mInput: \"" << input << "\"\033[0m" << std::endl;
  ScalarConverter::convert(input);
  std::cout << "----------------------------------------" << std::endl;
}

int main(int argc, char **argv) {
  if (argc > 1) {
    ScalarConverter::convert(argv[1]);
    return 0;
  }

  std::cout << "Running tests..." << std::endl;

  test_header("TEST 1: Char Literals");
  convert("c");
  convert("a");
  convert("0"); // Should detect as int 0 first, but display char '0'
  convert("*");

  test_header("TEST 2: Integer Literals");
  convert("42");
  convert("-42");
  convert("0");
  convert("2147483647");  // INT_MAX
  convert("-2147483648"); // INT_MIN

  test_header("TEST 3: Float/Double Literals");
  convert("42.0");
  convert("42.0f");
  convert("4.2");
  convert("4.2f");
  convert("-42.42");
  convert("-42.42f");

  test_header("TEST 4: Pseudo Literals (Special)");
  convert("nan");
  convert("nanf");
  convert("+inf");
  convert("+inff");
  convert("-inf");
  convert("-inff");

  test_header("TEST 5: Edge Cases & Overflows");
  convert("2147483648"); // Overflow Int Max (should print int: impossible)
  convert("1.5e5");      // Double precision scientific notation
  convert("0.0005f");    // Small float

  test_header("TEST 6: Invalid / Impossible Inputs");
  convert("hello");
  convert("42abc");  // Mixed garbage
  convert("42.0ff"); // Too many f's
  convert("..42");   // Multiple dots
  convert("");       // Empty string
  convert("f");      // Tricky one (should be impossible, not 0.0)

  return 0;
}
