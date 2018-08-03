#ifndef GLUCOSE_VEC_TEST_H
#define GLUCOSE_VEC_TEST_H

#include "glucose/TestFacade.hpp"
#include "glucose/Vec.hpp"
#include <iostream>

using namespace glucose;

#define assertVec3Eq(EXP0, EXP1, EXP2, ACTUAL, TOLERANCE)\
	assertFpEq(EXP0, ACTUAL[0], TOLERANCE);\
	assertFpEq(EXP1, ACTUAL[1], TOLERANCE);\
	assertFpEq(EXP2, ACTUAL[2], TOLERANCE)

TEST(Vec) {
	double tolerance = 0.01;
	double v = 9;

	Vec<3> a({v, v, v});
	Vec<3, double> b({4, 5, 6}); // Equivalent to the type above
	
	assertVec3Eq(v, v, v, a, tolerance);
	assertVec3Eq(4, 5, 6, b, tolerance);
	
	auto sum = a + b;
	auto difference = a - b;
	auto dot = a.dot(b);
	auto scaled = a * 10;
	auto normalized = a.normalize();
	auto len = a.length();
	auto size = a.size();
	
	assertVec3Eq(13, 14, 15, sum, tolerance);
	assertVec3Eq(5, 4, 3, difference, tolerance);
	assertFpEq(135, dot, tolerance);
	assertVec3Eq(90, 90, 90, scaled, tolerance);
	assertVec3Eq(0.5773, 0.5773, 0.5773, normalized, tolerance);
	assertFpEq(3, size, tolerance);
}

#endif // GLUCOSE_VEC_TEST_H
