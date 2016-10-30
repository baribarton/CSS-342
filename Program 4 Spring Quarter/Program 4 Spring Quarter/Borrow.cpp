//This class has one method that simulates a 
//customer borrowing a movie from the shop
#include "Borrow.h"
#include <iostream>
//Default constructor
Borrow::Borrow() : Transaction() { }

//Destructor
Borrow::~Borrow() { }

//subtracts one to the stock of the current movie
void Borrow::processTransaction()
{
	int stock = getMovie().getStock() - 1;
	//cout << "STOCK: " << stock << endl;
	getMovie().setStock(stock);
	//cout << "STOCK: " << getMovie().getStock() << endl;
}