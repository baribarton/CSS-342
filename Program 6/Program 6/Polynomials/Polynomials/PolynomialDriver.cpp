#include <iostream>
using namespace std;

#include "polynomial.h"

int main()
{
	Polynomial p1;

	p1.changeCoefficient(9, 9);
	cout << "p1 = " << p1 << endl;
	p1.changeCoefficient(3, 3);
	cout << "p1 = " << p1 << endl;
	p1.changeCoefficient(2, 2);
	cout << "p1 = " << p1 << endl;
	p1.changeCoefficient(9, 3);
	cout << "p1 = " << p1 << endl;
	p1.changeCoefficient(0, 3);
	cout << "p1 = " << p1 << endl;

	
	cout << "p1 degree: " << p1.degree() << endl;
	cout << "end" << endl;
}