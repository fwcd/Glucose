#ifndef GLUCOSE_BIT_SEQUENCE_TEST_H
#define GLUCOSE_BIT_SEQUENCE_TEST_H

#include "glucose/TestFacade.hpp"
#include "glucose/BitSequence.hpp"
#include <iostream>

TEST(BitSequence) {
	BitSequence seq;
	for (int i=0; i<100; i++) {
		++seq;
	}
	std::cout << seq.toString() << "\n";
}

#endif // GLUCOSE_BIT_SEQUENCE_TEST_H
