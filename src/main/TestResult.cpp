#include "glucose/TestResult.hpp"

namespace glucose {

TestResult::TestResult() {
	failed = false;
	messagePresent = false;
}

TestResult::~TestResult() {}

void TestResult::failTest(std::string message) {
	failed = true;
	messagePresent = true;
	this->message = message;
}

void TestResult::passTest(std::string) {
	failed = false;
	messagePresent = true;
	this->message = message;
}

bool TestResult::hasFailed() { return this->failed; }
	
bool TestResult::hasMessage() { return this->messagePresent; }

std::string TestResult::getMessage() { return this->message; }

}
