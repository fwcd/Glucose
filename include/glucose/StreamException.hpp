#ifndef GLUCOSE_STREAM_EXCEPTION_HPP
#define GLUCOSE_STREAM_EXCEPTION_HPP

#include "GlucoseException.hpp"

namespace glucose {

class StreamException : public GlucoseException {
public:
	StreamException(std::string msg) : GlucoseException(msg) {}
};

} /* namespace glucose */

#endif /* GLUCOSE_STREAM_EXCEPTION_HPP */
