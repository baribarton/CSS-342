#include "longint.h"
#include <iostream>
using namespace std;

//reads a string of numbers to convert to a Deque
LongInt::LongInt(const string longNumber)
{
	string newString = "0123456789";
	if (newString[0] = '-') {
		negative = true;
	}

	for (int i = 0; i < longNumber.length(); i++) {
		if (newString.find(longNumber[i]) != string::npos) {
			digits.addBack(longNumber.at(i));
		}
	}
	removeZeros();
}

//copy constructor
LongInt::LongInt(const LongInt & rhs)
{
	negative = rhs.negative;
	Deque<char>(rhs.digits);
}

//initializes item to zero
LongInt::LongInt()
{
	negative = false;
	digits.addBack('0');
}

LongInt::~LongInt()
{
	digits.clear();
}

inline LongInt LongInt::operator+(const LongInt & rhs) const
{
	return LongInt();
}