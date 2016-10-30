//This class has one method that simulates a 
//customer returning a movie from the shop
#include "Return.h"

//Default constructor
Return::Return() : Transaction() { }

//Destructor
Return::~Return() { }

//adds one to the stock of the current movie
void Return::processTransaction()
{
	getMovie().setStock(getMovie().getStock() + 1);
}