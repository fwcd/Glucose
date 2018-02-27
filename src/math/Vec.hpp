/*
 * VectorND.hpp
 *
 *  Created on: 07.02.2018
 */

#include <cmath>
#include <functional>
#include <initializer_list>
#include <string>
#include <vector>

#ifndef MATH_VEC_HPP_
#define MATH_VEC_HPP_

namespace glucose {

/**
 * An immutable, n-dimensional (numerical) vector.
 */
template <int SIZE, typename T = double> class Vec {
public:
	explicit Vec(std::initializer_list<T> values) {
		data = new std::vector<T>(values);
	}

	Vec(const Vec<SIZE, T>& other) {
		data = new std::vector<T>(*other.data);
	}

	virtual ~Vec() {
		delete data;
	}

	Vec<SIZE, T> operator +(const Vec<SIZE, T>& other) {
		return combine(other, [](T a, T b) -> T { return a + b; });
	}

	Vec<SIZE, T> operator -(const Vec<SIZE, T>& other) {
		return combine(other, [](T a, T b) -> T { return a - b; });
	}

	Vec<SIZE, T> operator *(double factor) {
		return map([factor](T x) -> T { return x * factor; });
	}

	const double operator [](int index) {
		return (*data)[index];
	}

	bool operator ==(const Vec<SIZE, T>& other) {
		for (int i=0; i<SIZE; i++) {
			// TODO: Implement tolerance to deal with floating point inaccuracies
			if ((*data)[i] != (*other.data)[i]) {
				return false;
			}
		}

		return true;
	}

	Vec<SIZE, T> with(int index, double value) {
		std::vector<T> result(SIZE);
		result[index] = value;
		return Vec<SIZE, T>(result);
	}

	Vec<SIZE, T> normalize() {
		double len = length();
		return map([len](T x) -> T { return (T) (x / len); });
	}

	T dot(const Vec<SIZE, T>& other) {
		T result = 0;

		for (int i=0; i<SIZE; i++) {
			result += (*data)[i] * (*other.data)[i];
		}

		return result;
	}

	int size() const {
		return SIZE;
	}

	double length() {
		double length = 0;

		for (double component : (*data)) {
			length += component * component;
		}

		return sqrt(length);
	}

	Vec<SIZE, T> map(std::function<T(T)> mapper) {
		std::vector<T> mapped(SIZE);

		for (int i=0; i<SIZE; i++) {
			mapped[i] = mapper((*data)[i]);
		}

		return Vec<SIZE, T>(mapped);
	}

	Vec<SIZE, T> combine(const Vec<SIZE, T>& other, std::function<T(T, T)> combiner) {
		std::vector<T> combined(SIZE);

		for (int i=0; i<SIZE; i++) {
			combined[i] = combiner((*data)[i], (*other.data)[i]);
		}

		return Vec<SIZE, T>(combined);
	}

	T reduce(std::function<T(T, T)> associativeAccumulator) {
		T reduced = (*data)[0];

		for (int i=1; i<SIZE; i++) {
			reduced = associativeAccumulator(reduced, (*data)[i]);
		}

		return reduced;
	}

	const T getX() { return (*data)[0]; }

	const T getY() { return (*data)[1]; }

	const T getZ() { return (*data)[2]; }

	std::string toString() {
		std::string str;
		str += "[";

		for (T component : (*data)) {
			str += std::to_string(component) + ", ";
		}

		str.erase(str.length() - 2, 2);
		str += "]";
		return str;
	}
private:
	const std::vector<T>* data;

	explicit Vec(const std::vector<T>& values) {
		data = new std::vector<T>(values);
	}
};

} /* namespace glucose */

#endif /* MATH_VEC_HPP_ */
