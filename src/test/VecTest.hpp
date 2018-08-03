#ifndef GLUCOSE_VEC_TEST_H
#define GLUCOSE_VEC_TEST_H

#include "glucose/TestFacade.hpp"
#include "glucose/Vec.hpp"
#include <iostream>

using namespace glucose;

TEST(Vec) {
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
}

#endif // GLUCOSE_VEC_TEST_H
