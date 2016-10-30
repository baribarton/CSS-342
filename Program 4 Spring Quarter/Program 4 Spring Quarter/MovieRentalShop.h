//------------------------------------------------------------------------------
// The .h file used for the Linked List implementation
//
//------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include "MovieList.h"
#include "CustomerList.h"
#include "TransactionHistory.h"
//------------------------------------------------------------------------------
class MovieRentalShop
{
public:
	MovieRentalShop(); //constructor
	~MovieRentalShop(); //destructor
	void initializeCommandFile(ifstream& commandFile); //the overall command method for the txt
    void initializeMovieList(ifstream& moviesFile);
    void initializeCustomerList(ifstream& customerFile);
	
private:
	MovieList movieList;
	CustomerList customerList;
	TransactionHistory transactionHistory;
};