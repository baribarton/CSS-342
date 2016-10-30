#include <iostream>
using namespace std;
#include "polynomial.h"

int main()
{
	Polynomial p1, p2, p3, p4;

	p1.changeCoefficient(3, 3);
	cout << "p1 = " << p1 << endl;
	p1.changeCoefficient(1, 1);
	cout << "p1 = " << p1 << endl;
	p1.changeCoefficient(2, 2);

	p2.changeCoefficient(3, 3);
	p2.changeCoefficient(2, 2);
	p2.changeCoefficient(1, 1);

	cout << "p1 = " << p1 << endl;
	if (p1 == p2) {
		cout << "equal" << endl;
	}
	else {
		cout << "not equal" << endl;
	}
	cout << "p2 = " << p2 << endl;
	cout << "p1 - p2 = " << p1 - p2 << endl;

	cout << "p1 = " << p1 << endl;
	p1.changeCoefficient(4, 3);
	p1.changeCoefficient(7, 2);
	p1.changeCoefficient(4, 4);

	p2.changeCoefficient(2, 2);
	p2.changeCoefficient(3, 3);
	p2.changeCoefficient(6, 5);
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

	cout << "find a coefficient with a power of 2: " << p1.coefficient(2) << endl;
	cout << "find a coefficient with a power of 9: " << p1.coefficient(9) << endl;
	
	cout << "p1 + p2 = " << p1 + p2 << endl;
	cout << "p1 - p2 = " << p1 - p2 << endl;

	p1 = p2;

	cout << "p1 = " << p1 << endl;

	p3.changeCoefficient(1, 1);
	p3.changeCoefficient(2, 2);
	cout << "p3 = " << p3 << endl;
	
	p3 = Polynomial(p1);
	cout << "p3 = " << p3 << endl;

	p3 += p1;

	cout << "p3 = " << p3 << endl;
	cout << "p1 degree: " << p1.degree() << endl;
}