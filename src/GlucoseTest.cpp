/*
 * GlucoseTest.cpp
 *
 * Contains a main method for the purpose of experimentation.
 * Proper unit testing support is planned.
 *
 *  Created on: 07.02.2018
 */

#include <iostream>
#include <string>

#include "exception/NoSuchElementException.h"
#include "math/VectorND.h"
#include "structs/Optional.h"

using namespace glucose;

int main() {
	std::cout << "\n==== VectorND testing ====\n\n";

	VectorND a({1, 2, 3});
	VectorND b({4, 5, 6});

	std::cout << "Adding:\t\t" << (a + b).toString() << "\n";
	std::cout << "Subtracting:\t" << (a - b).toString() << "\n";
	std::cout << "Dotting:\t" << a.dot(b) << "\n";
	std::cout << "Scaling:\t" << (a * 10).toString() << "\n";
	std::cout << "Random Access:\t" << a[0] << "\n";
	std::cout << "Normalizing:\t" << a.normalize().toString() << "\n";
	std::cout << "Abs/Length:\t" << a.length() << "\n";
	std::cout << "Size:\t\t" << a.size() << "\n";

	std::cout << "\n==== Optional testing ====\n\n";

	int v = 5;
	Optional<int> emptyInt;
	Optional<int> filledInt(&v);

	std::cout << "Empty:\t\t" << emptyInt.toString() << "\n";
	std::cout << "Filled:\t\t" << filledInt.toString() << "\n";
	std::cout << "Unwrapped:\t" << *filledInt << "\n";

	try {
		*emptyInt;
	} catch (const NoSuchElementException& e) {
		std::cout << "Whoops, almost tried to dereference an empty optional.\n";
	}

	return 0;
}
