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
	
	assertFalse(emptyOpt.isPresent());
	assertTrue(filledOpt.isPresent());
}

#endif // GLUCOSE_OPTIONAL_TEST_H
