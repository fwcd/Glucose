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
	virtual void run(TestResult& result);\
	virtual std::string getName() { return name; }\
};\
void TEST_BASE_NAME ## Test::run(TestResult& unitTestResult)

#define fail(MSG) unitTestResult.fail(MSG); return
#define pass(MSG) unitTestResult.pass(MSG); return
#define assertTrue(EXPECTED, ACTUAL)\
	if (!ACTUAL) fail("Expected true but was false")
#define assertFalse(EXPECTED, ACTUAL)\
	if (ACTUAL) fail("Expected false but was true")
#define assertNumEq(EXPECTED, ACTUAL)\
	if (EXPECTED != ACTUAL) fail("Expected int " + std::to_string(EXPECTED) + " but was " + std::to_string(ACTUAL))
#define assertStrEq(EXPECTED, ACTUAL)\
	if (EXPECTED != ACTUAL) fail("Expected string " + EXPECTED + " but was " + ACTUAL)

}

#endif // GLUCOSE_TEST_FACADE_H
