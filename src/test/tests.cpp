#include <iostream>
#include "glucose/TestRunner.hpp"

#include "VecTest.hpp"
#include "BitSequenceTest.hpp"
#include "OptionalTest.hpp"

using namespace glucose;

int main() {
	std::cout << "C++ Version: " << __cplusplus << std::endl;
	std::cout << "--- Running tests ---" << std::endl;
	
	TestRunner({
		new VecTest(),
		new BitSequenceTest(),
		new OptionalTest()
	}).runAllTests();
	
	return 0;
}
