/*
 * NoSuchElementException.h
 *
 *  Created on: 10.02.2018
 */

#ifndef EXCEPTION_NOSUCHELEMENTEXCEPTION_H_
#define EXCEPTION_NOSUCHELEMENTEXCEPTION_H_

#include "GlucoseException.h"

namespace glucose {

class NoSuchElementException : public GlucoseException {
public:
	NoSuchElementException(std::string msg);

	virtual ~NoSuchElementException();
};

} /* namespace glucose */

#endif /* EXCEPTION_NOSUCHELEMENTEXCEPTION_H_ */
