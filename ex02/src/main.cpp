/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 23:50:34 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/10 06:58:21 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

Base* createA(void) {
	return (new A());
}
Base* createB(void) {
	return (new B());
}
Base* createC(void) {
	return (new C());
}

Base* generate(void) {
	typedef Base* (*classCreator)(void);

	classCreator creators[] = {&createA, &createB, &createC};

	const int numCreators = sizeof(creators) / sizeof(creators[0]);

	return creators[std::rand() % numCreators]();
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

void identify(Base& p) {
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}

	std::cout << "Unknown" << std::endl;
}

void test_header(std::string title) {
	std::cout << std::endl;
	std::cout << "\033[1;36m[ " << title << " ]\033[0m" << std::endl;
}

int main(void) {
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 5; i++) {
		test_header("TEST ROUND " + std::string(1, (i + '1')));

		Base* randomObject = generate();

		std::cout << "Pointer check:   ";
		identify(randomObject);

		std::cout << "Reference check: ";
		identify(*randomObject);

		delete randomObject;
	}

	return (0);
}
