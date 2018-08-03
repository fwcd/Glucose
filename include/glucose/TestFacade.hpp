#ifndef GLUCOSE_TEST_FACADE_H
#define GLUCOSE_TEST_FACADE_H

#include "TestCase.hpp"

namespace glucose {

// A convenient Test API including assertion macros

#define TEST(TEST_BASE_NAME)\
class TEST_BASE_NAME ## Test : public TestCase {\
private:\
	std::string name;\
public:\
	TEST_BASE_NAME ## Test() : name(#TEST_BASE_NAME) {}\
	virtual void run(TestResult& unitTestResult);\
	virtual std::string getName() { return name; }\
};\
void TEST_BASE_NAME ## Test::run(TestResult& unitTestResult)

#define fail(MSG) unitTestResult.failTest(MSG); return
#define pass(MSG) unitTestResult.passTest(MSG); return

/** Asserts that a boolean value is true */
#define assertTrue(ACTUAL)\
	if (!ACTUAL) unitTestResult.failTest("Expected true but was false")

/** Asserts that a boolean value is false */
#define assertFalse(ACTUAL)\
	if (ACTUAL) unitTestResult.failTest("Expected false but was true")

/** Asserts that two numbers are exactly equal */
#define assertNumEq(EXPECTED, ACTUAL)\
	if (EXPECTED != ACTUAL) unitTestResult.failTest("Expected number " + std::to_string(EXPECTED) + " but was " + std::to_string(ACTUAL))

/** Asserts that two floating point numbers are equal within a given tolerance */
#define assertFpEq(EXPECTED, ACTUAL, TOLERANCE)\
	if (std::abs(EXPECTED - ACTUAL) > TOLERANCE) unitTestResult.failTest("Expected number " + std::to_string(EXPECTED) + " but was " + std::to_string(ACTUAL))
	
/** Asserts that two strings are equal */
#define assertStrEq(EXPECTED, ACTUAL)\
	if (EXPECTED != ACTUAL) unitTestResult.failTest("Expected string " + EXPECTED + " but was " + ACTUAL)

}

#endif // GLUCOSE_TEST_FACADE_H
