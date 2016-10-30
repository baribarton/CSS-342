//This class has one method that simulates a 
//customer borrowing a movie from the shop
#ifndef Borrow_h
#define Borrow_h

#include "Movie.h"
#include "Transaction.h"
class Borrow : public Transaction
{
public:
	//Default constructor
	Borrow();

	//Destructor
	~Borrow();

	//subtracts one to the stock of the current movie
	virtual void processTransaction();
};

#endif