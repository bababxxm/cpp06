/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 18:51:45 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/21 19:22:57 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <sstream>
#include "Data.hpp"
#include "Serializer.hpp"

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
#define REVERSED "\033[7m"
#define DIM "\033[2m"
#define ITALIC "\033[3m"

template <typename T>
std::string paint(const std::string& color, T value) {
	std::stringstream ss;
	ss << color << value << RESET;
	return ss.str();
}

void test_header(const std::string& title) {
	std::cout << paint(B_CYAN, "[" + title + "]") << std::endl;
}

int main() {
	std::cout << "Running tests..." << std::endl;

	std::cout << paint(DIM, "----------------------------------------") << std::endl;

	test_header("TEST 1: Creating Data Object");
	Data originalData("Top Secret 42 Docs", 42, 99.9);

	std::cout << "Original Address: " << paint(B_YELLOW, &originalData) << std::endl;
	std::cout << "Original Name:    " << originalData.getName() << std::endl;
	std::cout << "Original Age:     " << originalData.getAge() << std::endl;

	std::cout << paint(DIM, "----------------------------------------") << std::endl;

	test_header("TEST 2: Serialization (Ptr -> uintptr_t)");
	uintptr_t raw = Serializer::serialize(&originalData);

	std::stringstream hexStream;
	hexStream << "0x" << std::hex << raw;
	std::cout << "Serialized Value: " << paint(B_YELLOW, hexStream.str()) << std::endl;

	std::cout << paint(DIM, "----------------------------------------") << std::endl;

	test_header("TEST 3: Deserialization (uintptr_t -> Ptr)");

	Data* restoredPtr = Serializer::deserialize(raw);
	std::cout << "restoredPtr Address: " << paint(B_YELLOW, &restoredPtr) << std::endl;
	std::cout << "restoredPtr Value:   " << paint(B_YELLOW, restoredPtr) << std::endl;

	std::cout << paint(DIM, "----------------------------------------") << std::endl;

	test_header("TEST 4: Verification");

	if (restoredPtr == &originalData)
		std::cout << paint(B_GREEN, "SUCCESS: Pointers match!") << std::endl;
	else
		std::cout << paint(B_RED, "FAILURE: Pointers do not match!") << std::endl;

	std::cout << "restoredPtr Address: " << paint(B_YELLOW, &restoredPtr) << std::endl;
	std::cout << "restoredPtr Name:    " << restoredPtr->getName() << std::endl;
	std::cout << "restoredPtr Age:     " << restoredPtr->getAge() << std::endl;

	std::cout << paint(DIM, "----------------------------------------") << std::endl;

	std::cout << "All tests are finished..." << std::endl;

	return 0;
}
