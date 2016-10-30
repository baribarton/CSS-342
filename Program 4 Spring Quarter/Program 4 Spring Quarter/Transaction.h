//This class handles transactions that are done between the customer and the shop
#ifndef Transaction_h
#define Transaction_h

#include "Movie.h"
class Transaction
{
public:
	//Default Constructor
	Transaction();

	//Destructor
	virtual ~Transaction();

	//This method will be overridden. It will either borrow or return a movie
	virtual void processTransaction();

	virtual bool operator==(const Transaction & transaction) const;

	//Accessor Methods: transactionType, mediaType, customerID, and movie
	char getTransactionType();
	char getMediaType();
	int getCustomerID();
	Movie getMovie();

	//Mutator Methods: transactionType, mediaType, customerID, and movie
	void setTransactionType(char newTransactionType);
	void setMediaType(char newMediaType);
	void setCustomerID(int newID);
	void setMovie(Movie newMovie);

private:
	char transactionType;	//'I', 'H', 'B', or 'R'
	char mediaType;
	int customerID;
	Movie movie;
};
#endif