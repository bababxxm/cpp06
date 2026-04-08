/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* main.cpp                                           :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2026/01/26 22:15:00 by sklaokli          #+#    #+#             */
/* Updated: 2026/01/26 22:45:00 by sklaokli         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

void test_header(std::string title) {
	std::cout << std::endl;
	std::cout << "\033[1;36m[ " << title << " ]\033[0m" << std::endl;
}

int main() {
	test_header("TEST 1: Creating Data Object");
	Data originalData("Top Secret 42 Docs", 42, 99.9);
	std::cout << "Original Address: " << &originalData << std::endl;
	std::cout << "Original Name:    " << originalData.getName() << std::endl;
	std::cout << "Original Age:     " << originalData.getAge() << std::endl;

	test_header("TEST 2: Serialization (Ptr -> uintptr_t)");
	uintptr_t raw = Serializer::serialize(&originalData);
	std::cout << "Serialized Value (Decimal): " << raw << std::endl;
	std::cout << "Serialized Value (Hex):     0x" << std::hex << raw << std::dec << std::endl;

	test_header("TEST 3: Deserialization (uintptr_t -> Ptr)");
	Data* restoredPtr = Serializer::deserialize(raw);
	std::cout << "Restored Address: " << restoredPtr << std::endl;
	test_header("TEST 4: Verification");

	if (restoredPtr == &originalData) {
		std::cout << "\033[1;32mSUCCESS: Pointers match!\033[0m" << std::endl;
	} else {
		std::cout << "\033[1;31mFAILURE: Pointers do not match!\033[0m" << std::endl;
	}

	if (restoredPtr->getName() == originalData.getName() &&
	    restoredPtr->getAge() == originalData.getAge()) {
		std::cout << "\033[1;32mSUCCESS: Data is intact!\033[0m" << std::endl;
	} else {
		std::cout << "\033[1;31mFAILURE: Data corrupted!\033[0m" << std::endl;
	}

	test_header("TEST 5: NULL Handling (Edge Case)");
	Data* nullPtr = NULL;
	uintptr_t serializedNull = Serializer::serialize(nullPtr);
	Data* deserializedNull = Serializer::deserialize(serializedNull);
	std::cout << "Original NULL:     " << nullPtr << std::endl;
	std::cout << "Serialized NULL:   " << serializedNull << std::endl;
	std::cout << "Deserialized NULL: " << deserializedNull << std::endl;

	if (deserializedNull == NULL) {
		std::cout << "\033[1;32mSUCCESS: NULL preserved!\033[0m" << std::endl;
	} else {
		std::cout << "\033[1;31mFAILURE: NULL lost!\033[0m" << std::endl;
	}

	return 0;
}
