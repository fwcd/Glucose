/*
 * GlucoseTest.cpp
 *
 * Contains a main method for the purpose of experimentation.
 * Proper unit testing support is planned.
 *
 *  Created on: 07.02.2018
 */

#include <functional>
#include <iostream>

#include "math/VectorND.h"

int main() {
	glucose::VectorND a({1, 2, 3});
	glucose::VectorND b({4, 5, 6});

	std::cout << "Adding: " << (*(a + b)).toString() << "\n";
	std::cout << "Subtracting: " << (*(a - b)).toString() << "\n";
	std::cout << "Dotting: " << a.dot(b) << "\n";
	std::cout << "Scaling: " << (*(a * 10)).toString() << "\n";
	std::cout << "Random Access: " << a[0] << "\n";
	std::cout << "Normalizing: " << (*a.normalize()).toString() << "\n";
	std::cout << "Absolute/Length: " << a.length() << "\n";
	std::cout << "Size: " << a.size() << "\n";

	return 0;
}
