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
	size = p.size;
	head = p.head;
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

bool Polynomial::changeCoefficient(const double newCoefficient, const int power)
{
	Term *tempNode = new Term();
	tempNode = head;
	if (this->degree() < power) {
		insert(head, newCoefficient, power);
		/*if (newCoefficient == 0) {
			remove(head);
		}*/
		return false;
	}

	for (int i = 0; i < size; i++) {
		//if (tempNode != NULL) {
			if (tempNode->power == power) {
				tempNode->coeff = newCoefficient;
				if (newCoefficient == 0) {
					remove(tempNode);
				}
				return true;
			}
			else if (power > tempNode->power) {
				insert(tempNode, newCoefficient, power);
				return false;
			}
			else {
				tempNode = tempNode->next;


			}
		//}
	}

	return false;
}

bool Polynomial::insert(Term *position, const double newCoefficient, const int power)
{
	Term *newNode = new Term();
	newNode->coeff = newCoefficient;
	newNode->power = power;

	if (position == head) {

		if (size == 0) {
			newNode->next = head;
			newNode->prev = head;
			head = newNode;
		} else {
			newNode->next = head;
			newNode->prev = head->prev;
			head->prev->next = newNode;
			head->prev = newNode;
			head = newNode;
		}
	}
	else {
		newNode->next = position;
		newNode->prev = position->prev;
		position->prev = newNode;
		newNode->prev->next = newNode;
	}

	//cout << "tempNode coeff: " << newNode->coeff << endl << "tempNode power: " << newNode->power << endl;
	//cout << "coeff: " << newCoefficient << endl << "power: " << power << endl;

	size++;
	return true;
}

bool Polynomial::remove(Term *pos)
{
	//ensures that head still exists
	if (pos == head) {
		head->next->prev = head->prev;
		head->prev->next = head->next;
		head = head->next;
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