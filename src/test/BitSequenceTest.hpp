#ifndef GLUCOSE_BIT_SEQUENCE_TEST_H
#define GLUCOSE_BIT_SEQUENCE_TEST_H

#include "glucose/TestFacade.hpp"
#include "glucose/BitSequence.hpp"
#include <iostream>
#include <string>

bool stringHasEnding(const std::string& base, const std::string& end) {
	int baseLength = base.length();
	int endLength = end.length();
	if (baseLength >= endLength) {
		int offset = baseLength - endLength;
		return (base.compare(offset, endLength, end) == 0);
	} else {
		return false;
	}
}

TEST(BitSequence) {
	BitSequence seq;
	for (int i=0; i<100; i++) {
		++seq;
	}
	assertTrue(stringHasEnding(seq.toString(), "1100100"));
}

#endif // GLUCOSE_BIT_SEQUENCE_TEST_H
