#include <cstdlib>
#include <ctime>
#include <iostream>
#include <sstream>
#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"

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

Base* generate(void) {
	int r = std::rand() % 3;
	if (r == 0) return new A;
	if (r == 1) return new B;
	return new C;
}

void identify(Base* p) {
	std::cout << "Pointer check:   ";
	if (dynamic_cast<A*>(p))
		std::cout << paint(B_YELLOW, "A");
	else if (dynamic_cast<B*>(p))
		std::cout << paint(B_YELLOW, "B");
	else if (dynamic_cast<C*>(p))
		std::cout << paint(B_YELLOW, "C");
	std::cout << std::endl;
}

void identify(Base& p) {
	std::cout << "Reference check: ";
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << paint(B_MAGENTA, "A") << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << paint(B_MAGENTA, "B") << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << paint(B_MAGENTA, "C") << std::endl;
		return;
	} catch (...) {}
}

void test_header(std::string title) {
	std::cout << paint(B_CYAN, "[" + title + "]") << std::endl;
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::cout << "Running tests..." << std::endl;
	std::cout << paint(DIM, "----------------------------------------") << std::endl;

	for (int i = 0; i < 10; i++) {
		std::stringstream ss;
		ss << "TEST ROUND " << (i + 1);
		test_header(ss.str());

		Base* randomObject = generate();

		identify(randomObject);
		identify(*randomObject);

		delete randomObject;
		std::cout << paint(DIM, "----------------------------------------") << std::endl;
	}

	std::cout << "All tests are finished..." << std::endl;

	return 0;
}
