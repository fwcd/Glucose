#ifndef GLUCOSE_OPTIONAL_TEST_H
#define GLUCOSE_OPTIONAL_TEST_H

#include "glucose/TestFacade.hpp"
#include "glucose/Optional.hpp"
#include "glucose/NoSuchElementException.hpp"
#include <iostream>

using namespace glucose;

TEST(Optional) {
	double v = 20;
	
	Optional<double> emptyOpt;
	Optional<double> filledOpt(v);

	std::cout << "Empty:\t\t" << emptyOpt.toString() << "\n";
	std::cout << "Filled:\t\t" << filledOpt.toString() << "\n";
	std::cout << "Unwrapped:\t" << *filledOpt << "\n";
	
	try {
		*emptyOpt;
	} catch (const NoSuchElementException& e) {
		std::cout << "Whoops, almost tried to dereference an empty optional.\n";
	}
}

#endif // GLUCOSE_OPTIONAL_TEST_H
