/*
 * NoSuchElementException.cpp
 *
 *  Created on: 10.02.2018
 */

#include "NoSuchElementException.h"

#include <string>

namespace glucose {

NoSuchElementException::NoSuchElementException(std::string msg) : GlucoseException(msg) {
}

NoSuchElementException::~NoSuchElementException() {
}

} /* namespace glucose */
