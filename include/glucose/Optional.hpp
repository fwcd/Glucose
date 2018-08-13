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

	/** Returns the mapped value if present */
	template <typename R> Optional<R> map(std::function<R(T)> mapper) {
		if (present) {
			return Optional<R>(mapper(item));
		} else return Optional<R>();
	}

	/** Returns a mapped value if this and the returned optional are present */
	template <typename R> Optional<R> flatMap(std::function<Optional<R>(T)> mapper) {
		if (present) {
			Optional<R> mapped = mapper(item);
			if (mapped.present) {
				return Optional<R>(mapped.item);
			}
		}
		return Optional<R>();
	}

	bool isPresent() {
		return present;
	}
	
	Optional<T> orOptional(const Optional<T>& other) {
		if (present) {
			// Return a value-copy of this optional
			return *this;
		} else {
			return other;
		}
	}
	
	Optional<T> orOptionalGet(std::function<Optional<T>(void)> other) {
		if (present) {
			// Return a value-copy of this optional
			return *this;
		} else {
			return other();
		}
	}

	T orElseGet(std::function<T(void)> other) {
		return present ? item : other();
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
