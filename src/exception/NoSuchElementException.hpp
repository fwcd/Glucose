/*
 * NoSuchElementException.hpp
 *
 *  Created on: 10.02.2018
 */

#ifndef EXCEPTION_NOSUCHELEMENTEXCEPTION_HPP_
#define EXCEPTION_NOSUCHELEMENTEXCEPTION_HPP_

#include "../../src/exception/GlucoseException.hpp"

namespace glucose {

class NoSuchElementException : public GlucoseException {
public:
	NoSuchElementException(std::string msg) : GlucoseException(msg) {}

	virtual ~NoSuchElementException() {}
};

} /* namespace glucose */

#endif /* EXCEPTION_NOSUCHELEMENTEXCEPTION_HPP_ */
