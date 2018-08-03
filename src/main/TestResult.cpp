#include "glucose/TestResult.hpp"

namespace glucose {

TestResult::TestResult() {
	failed = false;
	messagePresent = false;
}

TestResult::~TestResult() {}

void TestResult::fail(const std::string& message) {
	failed = true;
	messagePresent = true;
	this->message = message;
}

void TestResult::pass(const std::string& message) {
	failed = false;
	messagePresent = true;
	this->message = message;
}

bool TestResult::hasFailed() { return this->failed; }
	
bool TestResult::hasMessage() { return this->messagePresent; }

std::string TestResult::getMessage() { return this->message; }

}
