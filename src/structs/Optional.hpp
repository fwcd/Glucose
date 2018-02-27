/*
 * Optional.hpp
 *
 *  Created on: 10.02.2018
 */

#ifndef STRUCTS_OPTIONAL_HPP_
#define STRUCTS_OPTIONAL_HPP_

#include <functional>
#include <sstream>
#include <string>

#include "../../src/exception/NoSuchElementException.hpp"

namespace glucose {

/**
 * Immutable optional type.
 */
template <typename T> class Optional {
public:
	Optional() {
		item = NULL;
	}

	Optional(T* obj) {
		item = obj;
	}

	virtual ~Optional() {
		if (isPresent()) { // Only call delete if item is not null already
			delete item;
		}
	}

	/**
	 * Maps the optional.
	 */
	template <typename R> Optional<R> map(std::function<R*(T)> mapper) {
		return Optional<R>(mapper(*item));
	}

	bool isPresent() {
		return item;
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
private:
	T* item;
};

} /* namespace glucose */

#endif /* STRUCTS_OPTIONAL_HPP_ */
