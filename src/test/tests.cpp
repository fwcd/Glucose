#include <iostream>
#include "glucose/TestRunner.hpp"

#include "VecTest.hpp"
#include "OptionalTest.hpp"
#include "StreamTest.hpp"

using namespace glucose;

int main() {
	std::cout << "C++ Version: " << __cplusplus << std::endl;
	std::cout << "--- Running tests ---" << std::endl;
	
	// The TestRunner takes ownership of the dynamically
	// allocated test cases which do not need to be explicitly
	// deallocated.
	
	TestRunner({
		new VecTest(),
		new OptionalTest(),
		new StreamTest()
	}).runAllTests();
	
	return 0;
}
