#include "glucose/BitSequence.hpp"

BitSequence::BitSequence() {
	data = std::vector<unsigned int>({0});
	usedBits = 1;
	smallestBit = false;
}

BitSequence::~BitSequence() {}

unsigned int BitSequence::getBitCapacity() {
	return INT_BITS * data.size();
}

bool BitSequence::getBit(int indexFromRight) {
	int containedByte = indexFromRight / 8;
	int indexInBit = indexFromRight % 8;
	return (data[data.size() - 1 - containedByte] >> indexInBit) & 1;
}

const BitSequence& BitSequence::operator++() {
	bool carry = true;
	int i = data.size() - 1;

	while (carry) {
		while (i < 0) {
			// TODO: Performance optimization
			data.insert(data.begin(), 0);
			i++;
		}

		unsigned int result = ++data[i];
		if (result == 0) {
			i--;
		} else {
			carry = false;
		}
	}

	if (smallestBit) {
		usedBits++;
	}

	smallestBit = !smallestBit;
	return *this;
}

std::string BitSequence::toIntsString() {
	std::stringstream stream;

	for (int v : data) {
		stream << v;
	}

	return stream.str();
}

std::string BitSequence::toString() {
	std::stringstream stream;

	for (int i=usedBits-1; i>=0; i--) {
		stream << (getBit(i) ? 1 : 0);
	}

	return stream.str();
}
