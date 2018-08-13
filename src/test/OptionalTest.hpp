#ifndef GLUCOSE_OPTIONAL_TEST_H
#define GLUCOSE_OPTIONAL_TEST_H

#include "glucose/TestFacade.hpp"
#include "glucose/Optional.hpp"
#include "glucose/NoSuchElementException.hpp"
#include <iostream>

using namespace glucose;

TEST(Optional) {
	double v = 20;
	double ten = 10;
	double tolerance = 0.001;
	
	Optional<double> emptyOpt;
	Optional<double> filledOpt(v);
	
	assertFalse(emptyOpt.isPresent());
	assertFalse(emptyOpt.map<double>([](auto x) { return x * 2; }).isPresent());
	assertTrue(filledOpt.isPresent());
	assertFpEq(50, *(filledOpt.map<double>([](auto x) { return x * 2.5; })), tolerance);
	assertFpEq(20, *filledOpt, tolerance);
	assertFpEq(10, emptyOpt.orElseRef(ten), tolerance);
	assertFpEq(10, emptyOpt.orElse(10), tolerance);
	assertFpEq(10, emptyOpt.orElseGet([] { return 10; }), tolerance);
}

#endif // GLUCOSE_OPTIONAL_TEST_H
