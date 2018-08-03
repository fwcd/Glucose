#ifndef GLUCOSE_BIT_SEQUENCE_HPP
#define GLUCOSE_BIT_SEQUENCE_HPP

#include <limits>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#define INT_BITS std::numeric_limits<unsigned int>::digits

/**
 * A bit sequence stored in big endian notation.
 */
class BitSequence {
private:
	std::vector<unsigned int> data;
	int usedBits;
	bool smallestBit;
public:
	BitSequence();

	virtual ~BitSequence();

	unsigned int getBitCapacity();

	bool getBit(int indexFromRight);

	const BitSequence& operator++();

	std::string toIntsString();

	std::string toString();
};

#endif /* GLUCOSE_BIT_SEQUENCE_HPP */
