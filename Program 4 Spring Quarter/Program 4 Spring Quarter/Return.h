//This class has one method that simulates a 
//customer returning a movie from the shop
#ifndef Return_h
#define Return_h

#include "Movie.h"
#include "Transaction.h"
class Return : public Transaction
{
public:
	//Default constructor
	Return();

	//Destructor
	~Return();

	//adds one to the stock of the current movie
	virtual void processTransaction();
};

#endif