#ifndef GLUCOSE_TEST_CASE_H
#define GLUCOSE_TEST_CASE_H

#include "TestResult.hpp"
#include <string>

namespace glucose {

/** A basic unit test case interface */
class TestCase {
public:
	TestCase() {}
	
	virtual ~TestCase() {}
	
	virtual void run(TestResult& result) = 0;
	
	virtual std::string getName() = 0;
};

}

#endif // GLUCOSE_TEST_CASE_H
