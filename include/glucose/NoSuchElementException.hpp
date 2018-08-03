#ifndef GLUCOSE_NO_SUCH_ELEMENT_EXCEPTION_HPP
#define GLUCOSE_NO_SUCH_ELEMENT_EXCEPTION_HPP

#include "GlucoseException.hpp"

namespace glucose {

class NoSuchElementException : public GlucoseException {
public:
	NoSuchElementException(std::string msg) : GlucoseException(msg) {}
};

} /* namespace glucose */

#endif /* GLUCOSE_NO_SUCH_ELEMENT_EXCEPTION_HPP */
