/*
 * VectorND.cpp
 *
 *  Created on: 07.02.2018
 */

#include "VectorND.h"

#include <cmath>

#include "../exception/GlucoseException.h"

namespace glucose {

VectorND::VectorND(std::initializer_list<double> values) {
	data = new std::vector<double>(values);
}

VectorND::VectorND(const VectorND& other) {
	data = new std::vector<double>(*other.data);
}

VectorND::VectorND(const std::vector<double>& values) {
	data = &values;
}

VectorND::~VectorND() {
	delete data;
}

VectorND::Ptr VectorND::operator +(const VectorND& other) {
	return combine(other, [](double a, double b) -> double { return a + b; });
}

VectorND::Ptr VectorND::operator -(const VectorND& other) {
	return combine(other, [](double a, double b) -> double { return a - b; });
}

VectorND::Ptr VectorND::operator *(double factor) {
	return map([factor](double x) -> double { return x * factor; });
}

const double VectorND::operator [](int index) {
	return (*data)[index];
}

bool glucose::VectorND::operator ==(const VectorND& other) {
	int s = size();

	for (int i=0; i<s; i++) {
		// TODO: Implement tolerance to deal with floating point inaccuracies
		if ((*data)[i] != (*other.data)[i]) {
			return false;
		}
	}

	return true;
}

VectorND::Ptr VectorND::with(int index, double value) {
	std::vector<double>* result = new std::vector<double>(size());
	(*result)[index] = value;
	return VectorND::Ptr(new VectorND(*result));
}

VectorND::Ptr VectorND::normalize() {
	double len = length();
	return map([len](double x) -> double { return x / len; });
}

double VectorND::dot(const VectorND& other) {
	int s = size();
	assertEqualSize(s, other);
	double result = 0;

	for (int i=0; i<s; i++) {
		result += (*data)[i] * (*other.data)[i];
	}

	return result;
}

VectorND::Ptr VectorND::map(std::function<double(double)> mapper) {
	int s = size();
	std::vector<double>* mapped = new std::vector<double>(s);

	for (int i=0; i<s; i++) {
		(*mapped)[i] = mapper((*data)[i]);
	}

	return VectorND::Ptr(new VectorND(*mapped));
}

VectorND::Ptr VectorND::combine(const VectorND& other, std::function<double(double, double)> combiner) {
	int s = size();
	assertEqualSize(s, other);
	std::vector<double>* combined = new std::vector<double>(s);

	for (int i=0; i<s; i++) {
		(*combined)[i] = combiner((*data)[i], (*other.data)[i]);
	}

	return VectorND::Ptr(new VectorND(*combined));
}

double VectorND::reduce(std::function<double(double, double)> associativeAccumulator) {
	int s = size();
	double reduced = (*data)[0];

	for (int i=1; i<s; i++) {
		reduced = associativeAccumulator(reduced, (*data)[i]);
	}

	return reduced;
}

double VectorND::length() {
	double length = 0;

	for (double component : (*data)) {
		length += component * component;
	}

	return sqrt(length);
}

int VectorND::size() const {
	return data->size();
}

std::string VectorND::toString() {
	std::string str;
	str += "[";

	for (double component : (*data)) {
		str += std::to_string(component) + ", ";
	}

	str.erase(str.length() - 2, 2);
	str += "]";
	return str;
}

void VectorND::assertEqualSize(int size, const VectorND& other) const {
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

const double VectorND::getX() {
	return (*data)[0];
}

const double VectorND::getY() {
	return (*data)[1];
}

const double VectorND::getZ() {
	return (*data)[2];
}

} /* namespace glucose */
