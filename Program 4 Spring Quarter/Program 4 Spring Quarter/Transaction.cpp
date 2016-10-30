//This class handles transactions that are done between the customer and the shop
#include "Transaction.h"

//Default Constructor
Transaction::Transaction()
{
	transactionType = '\0';
	mediaType = '\0';
	customerID = 0000;	//Customer IDs are 4 numbers long
	movie = Movie();
}

//Destructor
Transaction::~Transaction() { }

//This method will be overridden. It will either borrow or return a movie
void Transaction::processTransaction() { }

bool Transaction::operator==(const Transaction & transaction) const
{
	return (transactionType == transaction.transactionType) && (mediaType == transaction.mediaType) && 
		(customerID == transaction.customerID) && (movie == transaction.movie);
}

//Accessor Methods: transactionType, mediaType, customerID, and movie
char Transaction::getTransactionType()
{
	return transactionType;
}

char Transaction::getMediaType()
{
	return mediaType;
}

int Transaction::getCustomerID()
{
	return customerID;
}

Movie Transaction::getMovie()
{
	return Movie(movie);
}

//Mutator Methods: transactionType, mediaType, customerID, and movie
void Transaction::setTransactionType(char newTransactionType)
{
	transactionType = newTransactionType;
}

void Transaction::setMediaType(char newMediaType)
{
	mediaType = newMediaType;
}

void Transaction::setCustomerID(int newID)
{
	customerID = newID;
}

void Transaction::setMovie(Movie newMovie)
{
	movie = Movie(newMovie);
}