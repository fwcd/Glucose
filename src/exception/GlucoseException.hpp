/*
 * GlucoseException.hpp
 *
 *  Created on: 08.02.2018
 */

#ifndef EXCEPTION_GLUCOSEEXCEPTION_HPP_
#define EXCEPTION_GLUCOSEEXCEPTION_HPP_

#include <stdexcept>
#include <string>

namespace glucose {

class GlucoseException : public std::runtime_error {
public:
	GlucoseException(std::string msg) : std::runtime_error(msg) {}

	virtual ~GlucoseException() {}
};

} /* namespace glucose */

#endif /* EXCEPTION_GLUCOSEEXCEPTION_HPP_ */
