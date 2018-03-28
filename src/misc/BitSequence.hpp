/*
 * BitSequence.hpp
 *
 *  Created on: 11.03.2018
 */

#ifndef MISC_BITSEQUENCE_HPP_
#define MISC_BITSEQUENCE_HPP_

#include <limits>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#define INT_BITS std::numeric_limits<unsigned int>::digits

/**
 * A bit sequence stored in big endian notation.
 */
class BitSequence { // TODO: Debugging
public:
	BitSequence() {
		data = std::vector<unsigned int>({0});
		usedBits = 1;
		smallestBit = false;
	}

	virtual ~BitSequence() {}

	unsigned int getBitCapacity() {
		return INT_BITS * data.size();
	}

	bool getBit(int indexFromRight) {
		int containedByte = indexFromRight / 8;
		int indexInBit = indexFromRight % 8;
		return (data[data.size() - 1 - containedByte] >> indexInBit) & 1;
	}

	const BitSequence& operator ++() {
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

	std::string toIntsString() {
		std::stringstream stream;

		for (int v : data) {
			stream << v;
		}

		return stream.str();
	}

	std::string toString() {
		std::stringstream stream;

		for (int i=usedBits-1; i>=0; i--) {
			stream << (getBit(i) ? 1 : 0);
		}

		return stream.str();
	}
private:
	std::vector<unsigned int> data;
	int usedBits;
	bool smallestBit;
};

#endif /* MISC_BITSEQUENCE_HPP_ */
