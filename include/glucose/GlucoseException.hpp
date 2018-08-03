#ifndef GLUCOSE_GLUCOSE_EXCEPTION_HPP
#define GLUCOSE_GLUCOSE_EXCEPTION_HPP

#include <stdexcept>
#include <string>

namespace glucose {

class GlucoseException : public std::runtime_error {
public:
	GlucoseException(std::string msg) : std::runtime_error(msg) {}
};

} /* namespace glucose */

#endif /* GLUCOSE_GLUCOSE_EXCEPTION_HPP */
