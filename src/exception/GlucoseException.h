/*
 * GlucoseException.h
 *
 *  Created on: 08.02.2018
 */

#ifndef MATH_GLUCOSEEXCEPTION_H_
#define MATH_GLUCOSEEXCEPTION_H_

#include <stdexcept>
#include <string>

namespace glucose {

class GlucoseException : public std::runtime_error {
public:
	GlucoseException(std::string msg);

	virtual ~GlucoseException();
};

} /* namespace glucose */

#endif /* MATH_GLUCOSEEXCEPTION_H_ */
