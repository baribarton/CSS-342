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
	remove0s();
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

//removes leading 0's from the number
void LongInt::removeZeros() {
	if (digits.size() > 1) {
		while (digits.getFront() == '0') {
			digits.removeFront();
		}
	}
}

const LongInt &LongInt::operator=(const LongInt &rhs) {

}

LongInt & operator+(const LongInt & rhs)
{
	
}

istream & operator>>(istream & in, LongInt & rhs)
{
	string newString;
	rhs = *new LongInt(newString);
	in >> rhs;
	return in;
}

ostream &operator<<(ostream &out, const LongInt &rhs) {
	Deque<char> temp = rhs.digits;
	LongInt temp2(rhs);

	if (rhs.negative == true) {
		out << '-';
	}

	while (!temp.isEmpty()) {
		out << temp.removeFront();
	}

	return out;
}