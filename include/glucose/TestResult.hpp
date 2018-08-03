#ifndef GLUCOSE_TEST_RESULT_H
#define GLUCOSE_TEST_RESULT_H

#include <string>

namespace glucose {

/** A unit testing result */
class TestResult {
private:
	bool failed;
	bool messagePresent;
	std::string message;
public:
	TestResult();
	
	virtual ~TestResult();
	
	void failTest(std::string message);
	
	void passTest(std::string message);
	
	bool hasFailed();
	
	bool hasMessage();
	
	std::string getMessage();
};

}

#endif // GLUCOSE_TEST_RESULT_H
