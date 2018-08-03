#ifndef GLUCOSE_OPTIONAL_HPP
#define GLUCOSE_OPTIONAL_HPP

#include <functional>
#include <sstream>
#include <string>

#include "NoSuchElementException.hpp"

namespace glucose {

/**
 * Immutable optional type.
 */
template <typename T> class Optional {
private:
	T* item;
public:
	Optional() {
		item = 0;
	}

	Optional(const T& obj) {
		item = new T(obj);
	}

	Optional(const T& obj, bool performCopy) {
		if (performCopy) {
			item = new T(obj);
		} else {
			item = &obj;
		}
	}

	virtual ~Optional() {
		if (isPresent()) { // Only call delete if item is not null already
			delete item;
		}
	}

	/**
	 * Maps the optional.
	 */
	template <typename R> Optional<R> map(std::function<R(T)> mapper) {
		return Optional<R>(mapper(*item));
	}

	bool isPresent() {
		return item != 0;
	}

	const T& orElse(const T& other) {
		return isPresent() ? (*item) : other;
	}

	/**
	 * Unwraps the optional.
	 */
	const T& operator *() {
		if (isPresent()) {
			return *item;
		} else {
			throw NoSuchElementException("Tried to unwrap empty optional");
		}
	}

	std::string toString() {
		if (isPresent()) {
			std::ostringstream address;
			address << static_cast<const void*>(item);
			return "Optional pointing to " + address.str();
		} else {
			return "Empty optional";
		}
	}
};

} /* namespace glucose */

#endif /* GLUCOSE_OPTIONAL_HPP */
