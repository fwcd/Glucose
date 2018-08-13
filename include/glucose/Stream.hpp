#ifndef GLUCOSE_STREAM_H
#define GLUCOSE_STREAM_H

#include <vector>
#include <utility>
#include <initializer_list>
#include <functional>

namespace glucose {

/**
 * A lazily evaluated sequence of operations
 * on a vector
 */
template <typename T> class Stream {
private:
	std::vector<T> base;
	std::vector<std::function<void(std::vector<T>)>> operations;
public:
	/** Constructs an empty stream */
	Stream() {}
	
	/** Constructs a stream using the given items */
	Stream(std::initializer_list<T> items) : base(items) {}
	
	/** Constructs a stream using the given vector */
	Stream(std::vector<T> items) : base(items) {}
	
	virtual ~Stream() {}
};

}

#endif // GLUCOSE_STREAM_H
