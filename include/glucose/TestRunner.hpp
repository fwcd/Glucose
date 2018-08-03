#ifndef GLUCOSE_TEST_SUITE_H
#define GLUCOSE_TEST_SUITE_H

#include <vector>
#include <memory>
#include "TestCase.hpp"

namespace glucose {

/** A unit test runner */
class TestRunner {
private:
	std::vector<std::unique_ptr<TestCase>> tests;
public:
	TestRunner(std::initializer_list<TestCase*> tests);
	
	virtual ~TestRunner();
	
	void runAllTests();
};

}

#endif // GLUCOSE_TEST_SUITE_H
