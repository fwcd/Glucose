/*
 * ByteSequence.hpp
 *
 *  Created on: 11.03.2018
 */

#ifndef MISC_BITSEQUENCE_HPP_
#define MISC_BITSEQUENCE_HPP_

#include <sstream>
#include <limits>
#include <memory>
#include <string>
#include <vector>

#define INT_BITS std::numeric_limits<unsigned int>::digits

/**
 * A bit sequence stored in big endian notation.
 */
class BitSequence {
public:
	BitSequence() {
		data = std::unique_ptr<std::vector<unsigned int>>(new std::vector<unsigned int>({0}));
		usedBits = 1;
		highestBit = false;
	}

	virtual ~BitSequence() {}

	unsigned int getBitCapacity() {
		return INT_BITS * data->size();
	}

	bool getBit(int indexFromRight) {
		int containedByte = indexFromRight / 8;
		int indexInBit = indexFromRight % 8;
		return ((*data)[data->size() - 1 - containedByte] >> indexInBit) & 1;
	}

	const BitSequence& operator ++() {
		// TODO: Debug this

		if (usedBits % INT_BITS == 0) {
			data->push_back(0);
		} else {
			(*data)[data->size() - 1]++;
		}

		if (highestBit) {
			usedBits++;
		}
		highestBit = !highestBit;
		return *this;
	}

	std::string toString() {
		std::stringstream stream;

		for (int i=usedBits-1; i>=0; i--) {
			stream << (getBit(i) ? 1 : 0);
		}

		return stream.str();
	}
private:
	std::unique_ptr<std::vector<unsigned int>> data;
	int usedBits;
	bool highestBit;
};

#endif /* MISC_BITSEQUENCE_HPP_ */
