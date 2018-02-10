/*
 * VectorND.h
 *
 *  Created on: 07.02.2018
 */

#include <functional>
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

#ifndef MATH_VECTORND_H_
#define MATH_VECTORND_H_

namespace glucose {

/**
 * An immutable, n-dimensional, double-valued vector.
 */
class VectorND {
public:
	explicit VectorND(std::initializer_list<double> values);

	VectorND(const VectorND& other);

	virtual ~VectorND();

	VectorND operator +(const VectorND& other);

	VectorND operator -(const VectorND& other);

	VectorND operator *(double factor);

	const double operator [](int index);

	bool operator ==(const VectorND& other);

	VectorND with(int index, double value);

	VectorND normalize();

	double dot(const VectorND& other);

	double length();

	int size() const;

	VectorND map(std::function<double(double)> mapper);

	VectorND combine(const VectorND& other, std::function<double(double, double)> combiner);

	double reduce(std::function<double(double, double)> associativeAccumulator);

	const double getX();

	const double getY();

	const double getZ();

	std::string toString();
private:
	const std::vector<double>* data;

	explicit VectorND(const std::vector<double>& values);

	void assertEqualSize(int size, const VectorND& other) const;
};

} /* namespace glucose */

#endif /* MATH_VECTORND_H_ */
