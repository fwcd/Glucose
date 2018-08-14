#ifndef GLUCOSE_STREAM_TEST_H
#define GLUCOSE_STREAM_TEST_H

#include "glucose/TestFacade.hpp"
#include "glucose/Stream.hpp"
#include <vector>

using namespace glucose;

TEST(Stream) {
	double tolerance = 0.1;
	std::vector<double> result(Stream<int>{8, 2, 3}
		.map<int>([] (int v) { return v * 5; })
		.filter([] (int v) { return (v % 2) == 0; })
		.map<double>([] (int v) { return v / 2.5; })
		.toVector());
	assertNumEq(2, result.size());
	assertFpEq(16, result[0], tolerance);
	assertFpEq(4, result[1], tolerance);
}

#endif // GLUCOSE_STREAM_TEST_H
