#ifndef GLUCOSE_TEST_EXCEPTION_HPP
#define GLUCOSE_TEST_EXCEPTION_HPP

#include "GlucoseException.hpp"

namespace glucose {

class TestException : public GlucoseException {
public:
	TestException(std::string msg) : GlucoseException(msg) {}
};

} /* namespace glucose */

#endif /* GLUCOSE_TEST_EXCEPTION_HPP */
