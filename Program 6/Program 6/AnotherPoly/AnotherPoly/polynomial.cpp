#include "polynomial.h"

ostream & operator<<(ostream & output, const Polynomial & p)
{
	Polynomial::Term *temp = new Polynomial::Term();
	temp = p.head;

	for (int i = 0; i < p.size; i++) {
		if (temp != NULL) {
			//if (temp->coeff != 0) {
			if (temp->coeff != 1) {
				output << temp->coeff;
			}
			output << "x";

			if (temp->power != 1) {
				output << "^" << temp->power;
			}
			//}
			temp = temp->next;
		}
		if (i != p.size - 1) {
			output << " + ";
		}
	}
	output << endl << "Size = " << p.size << endl;
	return output;
}

//default constructor
Polynomial::Polynomial()
{
	size = 0;

	Term *dummyHeader = new Term();
	dummyHeader->next = dummyHeader;
	dummyHeader->prev = dummyHeader;
	dummyHeader->power = 0;
	dummyHeader->coeff = 0;

	head = dummyHeader;
}

Polynomial::Polynomial(const Polynomial & p)
{
	size = 0;

	Term *dummyHeader = new Term();
	dummyHeader->next = dummyHeader;
	dummyHeader->prev = dummyHeader;
	dummyHeader->power = 0;
	dummyHeader->coeff = 0;

	head = dummyHeader;

	*this = p;
}

Polynomial::~Polynomial()
{
	Term *tempNode;
	tempNode = head;

	for (int i = 0; i < size; i++) {
		tempNode = tempNode->next;
		remove(tempNode->prev);
	}
}

//Returns the degree of a polynomial.
//For example, when p1 = 4x5 + 7x3 - x2 + 9, p1.degree( ) is 5
int Polynomial::degree() const
{
	Term *temp = new Term();
	temp = head;

	int degree = temp->power;

	//finds term with the highest power
	for (int i = 0; i < size; i++) {
		if (temp != NULL) {
			if (temp->power > degree) {
				degree = temp->power;
			}
			temp = temp->next;
		}
	}
	return degree;
}

//Returns the coefficient of the xpower term
double Polynomial::coefficient(const int power) const
{
	Term *current = new Term();
	current = head;

	for (int i = 0; i < size; i++) {
		if (current->power == power) {
			return current->coeff;
		}
		current = current->next;
	}
	return 0;
}

//Replaces the coefficient of the xpower term with newCoeffcient
bool Polynomial::changeCoefficient(const double newCoefficient, const int power)
{
	Term *tempNode = new Term();
	tempNode = head;

	for (int i = 0; i < size; i++) {
		if (tempNode != NULL) {
			if (tempNode->power == power) {

				if (newCoefficient == 0) {
					//cout << "the power of head is: " << head->power << endl;
					return remove(tempNode);
					//cout << "the power of head is: " << head->power << endl;
				}
				tempNode->coeff = newCoefficient;
				return true;
			}

			//ensures that terms with coeff = 0 are not added
			if ((i == size - 1) && (newCoefficient == 0)) {
				return false;
			}

			tempNode = tempNode->next;
		}
	}
	
	return insert(head, newCoefficient, power);
}

//Add two polynomials or subtract the 2nd polynomial from the 1st one.
Polynomial Polynomial::operator+(const Polynomial & p) const
{
	Polynomial newPolynomial;
	
	Term *currentNode1 = new Term();
	Term *currentNode2 = new Term();

	currentNode1 = p.head;
	for (int i = 0; i < p.size; i++) {
		currentNode2 = this->head;
		for (int j = 0; j < this->size; j++) {
			if (currentNode1->power == currentNode2->power) {
				newPolynomial.changeCoefficient(currentNode1->coeff + currentNode2->coeff, currentNode1->power);
			}
			currentNode2 = currentNode2->next;
		}
		currentNode1 = currentNode1->next;
	}

	Term *newNode = new Term();
	newNode = newPolynomial.head;
	currentNode1 = p.head;

	for (int i = 0; i < p.size; i++) {
		bool isAdded = false;
		for (int j = 0; i < newPolynomial.size; i++) {
			if (newNode->power == currentNode1->power) {
				isAdded = true;
			}
			newNode = newNode->next;
		}

		if (!isAdded) {
			newPolynomial.changeCoefficient(currentNode1->coeff, currentNode1->power);
		}
		currentNode1 = currentNode1->next;
	}

	newNode = newPolynomial.head;
	currentNode2 = head;
	for (int i = 0; i < size; i++) {
		bool isAdded = false;
		for (int j = 0; i < newPolynomial.size; i++) {
			if (newNode->power == currentNode2->power) {
				isAdded = true;
			}
			newNode = newNode->next;
		}

		if (!isAdded) {
			newPolynomial.changeCoefficient(currentNode2->coeff, currentNode2->power);
		}
		currentNode2 = currentNode2->next;
	}
	return newPolynomial;
}

//overloads minus operator
Polynomial Polynomial::operator-(const Polynomial & p) const
{
	Polynomial newPolynomial;

	Term *currentNode1 = new Term();
	Term *currentNode2 = new Term();

	currentNode1 = p.head;
	for (int i = 0; i < p.size; i++) {
		currentNode2 = this->head;
		for (int j = 0; j < this->size; j++) {
			if (currentNode1->power == currentNode2->power) {
				newPolynomial.changeCoefficient(currentNode2->coeff - currentNode1->coeff, currentNode1->power);
			}
			currentNode2 = currentNode2->next;
		}
		currentNode1 = currentNode1->next;
	}

	Term *newNode = new Term();
	newNode = newPolynomial.head;
	currentNode1 = p.head;

	for (int i = 0; i < p.size; i++) {
		bool isAdded = false;
		for (int j = 0; i < newPolynomial.size; i++) {
			if (newNode->power == currentNode1->power) {
				isAdded = true;
			}
			newNode = newNode->next;
		}

		if (!isAdded) {
			newPolynomial.changeCoefficient(currentNode1->coeff, currentNode1->power);
		}
		currentNode1 = currentNode1->next;
	}

	newNode = newPolynomial.head;
	currentNode2 = head;
	for (int i = 0; i < size; i++) {
		bool isAdded = false;
		for (int j = 0; i < newPolynomial.size; i++) {
			if (newNode->power == currentNode2->power) {
				isAdded = true;
			}
			newNode = newNode->next;
		}

		if (!isAdded) {
			newPolynomial.changeCoefficient(currentNode2->coeff, currentNode2->power);
		}
		currentNode2 = currentNode2->next;
	}
	return newPolynomial;
}

//Returns true in == when corresponding terms of two given polynomial matches each other, otherwise false
bool Polynomial::operator==(const Polynomial & p) const
{
	Term *tempNode1 = head;
	Term *tempNode2 = p.head;

	bool isEqual = false;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < p.size; j++) {
			if ((tempNode1->coeff == tempNode2->coeff) && (tempNode1->power == tempNode2->power)) {
				isEqual = true;
				break;
			}
		}

		if (!isEqual) {
			return false;
		}
	}
	return true;
}

//Returns true in == when corresponding terms of two given polynomial matches each other, otherwise false
bool Polynomial::operator!=(const Polynomial & p) const
{
	return *this == p;
}

//overloads assignment operator
Polynomial & Polynomial::operator=(const Polynomial & p)
{
	while (size > 0) {
		remove(head);
	}

	Term *other = p.head;

	for (int i = 0; i < p.size; other = other->next, i++) {
		changeCoefficient(other->coeff, other->power);
	}

	other = NULL;
	return *this;
}

//overloads += operater
Polynomial & Polynomial::operator+=(const Polynomial & p)
{
	return *this = *this + p;
}

//overloads -= operator
Polynomial & Polynomial::operator-=(const Polynomial & p)
{
	return *this = *this - p;
}

//This private member function inserts a new Term node with newCoefficient 
//and power just before the existing Term pointed by the pos 
//pointer. The insert function will be 
//used bychangeCoefficient to insert a new term.
bool Polynomial::insert(Term *position, const double newCoefficient, const int power)
{
	Term *newNode = new Term();
	newNode->coeff = newCoefficient;
	newNode->power = power;

	if (size == 0 || position == head) {
		newNode->next = head;
		newNode->prev = head;
		head = newNode;
	}
	else {
		newNode->next = position;
		newNode->prev = position->prev;
		position->prev = newNode;
		newNode->prev->next = newNode;
	}

	size++;
	
	return true;
}

//This private member function deletes the
//existing Term node pointed by the pos pointer. 
//The remove function will be used by changeCoefficient 
//to delete an existing term when its coefficient is changed in 0
//. In addition, 
//it will be used by a destructor and the 
//operator= to de-allocates all Term nodes.
bool Polynomial::remove(Term *pos)
{
	if (pos == head) {		
		head = pos->next;
		head->prev->next = head->next;
		head->next->prev = head->prev;
	}
	else if (size == 0) {
		head = NULL;
	}
	else {
		pos->next->prev = pos->prev;
		pos->prev->next = pos->next;
	}
	pos = NULL;
	delete pos;
	size--;

	return true;
}