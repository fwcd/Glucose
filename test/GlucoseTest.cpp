 /*
 * GlucoseTest.cpp
 *
 * Contains a main method for the purpose of experimentation.
 * Proper unit testing support is planned.
 *
 *  Created on: 07.02.2018
 */

#include <cstdlib>
#include <iostream>
#include <string>

#include "../src/exception/NoSuchElementException.hpp"
#include "../src/math/Vec.hpp"
#include "../src/structs/Optional.hpp"

using namespace glucose;

int main() {
	std::cout << "\n==== Double vector testing ====\n\n";

	double v = 9;

	Vec<3> a({v, v, v});
	Vec<3, double> b({4, 5, 6}); // Equivalent to the type above

	std::cout << "Adding:\t\t" << (a + b).toString() << "\n";
	std::cout << "Subtracting:\t" << (a - b).toString() << "\n";
	std::cout << "Dotting:\t" << a.dot(b) << "\n";
	std::cout << "Scaling:\t" << (a * 10).toString() << "\n";
	std::cout << "Random Access:\t" << a[0] << "\n";
	std::cout << "Normalizing:\t" << a.normalize().toString() << "\n";
	std::cout << "Abs/Length:\t" << a.length() << "\n";
	std::cout << "Size:\t\t" << a.size() << "\n";

	std::cout << "\n==== Optional testing ====\n\n";

	Optional<double> emptyOpt;
	Optional<double> filledOpt(&v);

	std::cout << "Empty:\t\t" << emptyOpt.toString() << "\n";
	std::cout << "Filled:\t\t" << filledOpt.toString() << "\n";
	std::cout << "Unwrapped:\t" << *filledOpt << "\n";

	try {
		*emptyOpt;
	} catch (const NoSuchElementException& e) {
		std::cout << "Whoops, almost tried to dereference an empty optional.\n";
	}

	return 0;
}
