#ifndef GLUCOSE_OPTIONAL_HPP
#define GLUCOSE_OPTIONAL_HPP

#include <functional>
#include <sstream>
#include <string>

#include "NoSuchElementException.hpp"

namespace glucose {

/**
 * Immutable optional type. Note that the current implementation
 * of Optional uses a default constructed instance of T when
 * the value is not present.
 */
template <typename T> class Optional {
private:
	bool present;
	T item;
public:
	Optional() : present(false) {}

	Optional(T obj) : item(obj), present(true) {}
	
	virtual ~Optional() {}

	/**
	 * Maps the optional.
	 */
	template <typename R> Optional<R> map(std::function<R(T)> mapper) {
		if (present) {
			return Optional<R>(mapper(item));
		} else return Optional<R>();
	}

	bool isPresent() {
		return present;
	}

	T orElseGet(std::function<T(void)> getter) {
		return present ? item : getter();
	}

	T orElse(T other) {
		return present ? item : other;
	}

	const T& orElseRef(const T& other) {
		return present ? item : other;
	}

	/** Unwraps the optional. */
	const T& operator*() {
		if (isPresent()) {
			return item;
		} else {
			throw NoSuchElementException("Tried to unwrap empty optional");
		}
	}
};

} /* namespace glucose */

#endif /* GLUCOSE_OPTIONAL_HPP */
