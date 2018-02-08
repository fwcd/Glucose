/*
 * GlucoseException.cpp
 *
 *  Created on: 08.02.2018
 */

#include "GlucoseException.h"

namespace glucose {

GlucoseException::GlucoseException(std::string msg) : std::runtime_error(msg) {

}

GlucoseException::~GlucoseException() {

}

} /* namespace glucose */
