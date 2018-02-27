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

#ifndef MATH_VECTORND_HPP_
#define MATH_VECTORND_HPP_

namespace glucose {

/**
 * An immutable, n-dimensional, double-valued vector.
 */
class VectorND {
public:
	explicit VectorND(std::initializer_list<double> values) {
		data = new std::vector<double>(values);
	}

	VectorND(const VectorND& other) {
		data = new std::vector<double>(*other.data);
	}

	virtual ~VectorND() {
		delete data;
	}

	VectorND operator +(const VectorND& other) {
		return combine(other, [](double a, double b) -> double { return a + b; });
	}

	VectorND operator -(const VectorND& other) {
		return combine(other, [](double a, double b) -> double { return a - b; });
	}

	VectorND operator *(double factor) {
		return map([factor](double x) -> double { return x * factor; });
	}

	const double operator [](int index) {
		return (*data)[index];
	}

	bool operator ==(const VectorND& other) {
		int s = size();

		for (int i=0; i<s; i++) {
			// TODO: Implement tolerance to deal with floating point inaccuracies
			if ((*data)[i] != (*other.data)[i]) {
				return false;
			}
		}

		return true;
	}

	VectorND with(int index, double value) {
		std::vector<double> result(size());
		result[index] = value;
		return VectorND(result);
	}

	VectorND normalize() {
		double len = length();
		return map([len](double x) -> double { return x / len; });
	}

	double dot(const VectorND& other) {
		int s = size();
		assertEqualSize(s, other);
		double result = 0;

		for (int i=0; i<s; i++) {
			result += (*data)[i] * (*other.data)[i];
		}

		return result;
	}

	double length() {
		double length = 0;

		for (double component : (*data)) {
			length += component * component;
		}

		return sqrt(length);
	}

	int size() const {
		return data->size();
	}

	VectorND map(std::function<double(double)> mapper) {
		int s = size();
		std::vector<double> mapped(s);

		for (int i=0; i<s; i++) {
			mapped[i] = mapper((*data)[i]);
		}

		return VectorND(mapped);
	}

	VectorND combine(const VectorND& other, std::function<double(double, double)> combiner) {
		int s = size();
		assertEqualSize(s, other);
		std::vector<double> combined(s);

		for (int i=0; i<s; i++) {
			combined[i] = combiner((*data)[i], (*other.data)[i]);
		}

		return VectorND(combined);
	}

	double reduce(std::function<double(double, double)> associativeAccumulator) {
		int s = size();
		double reduced = (*data)[0];

		for (int i=1; i<s; i++) {
			reduced = associativeAccumulator(reduced, (*data)[i]);
		}

		return reduced;
	}

	const double getX() { return (*data)[0]; }

	const double getY() { return (*data)[1]; }

	const double getZ() { return (*data)[2]; }

	std::string toString() {
		std::string str;
		str += "[";

		for (double component : (*data)) {
			str += std::to_string(component) + ", ";
		}

		str.erase(str.length() - 2, 2);
		str += "]";
		return str;
	}
private:
	const std::vector<double>* data;

	explicit VectorND(const std::vector<double>& values) {
		data = new std::vector<double>(values);
	}

	void assertEqualSize(int size, const VectorND& other) const {
		int otherSize = other.size();
		if (size != otherSize) {
			throw GlucoseException(
					"Vector size "
					+ std::to_string(size)
					+ " does not match the other vectors size "
					+ std::to_string(otherSize)
			);
		}
	}
};

} /* namespace glucose */

#endif /* MATH_VECTORND_HPP_ */
