#include "glucose/TestRunner.hpp"

#include <iostream>

namespace glucose {

TestRunner::TestRunner(std::initializer_list<TestCase*> tests) {
	for (auto* test : tests) {
		this->tests.push_back(std::unique_ptr<TestCase>(test));
	}
}

TestRunner::~TestRunner() {}

void TestRunner::runAllTests() {
	for (auto&& test : tests) {
		auto result = TestResult();
		test->run(result);
		if (result.hasFailed()) {
			std::cout << "FAILED " << test->getName();
		} else {
			std::cout << "PASSED " << test->getName();
		}
		if (result.hasMessage()) {
			std::cout << ": " << result.getMessage();
		}
		std::cout << std::endl;
	}
}

}
