//------------------------------------------------------------------------------
// This is the MovieRentalShop class that will over the overall class that sets
// the txt files for all the individual classes
//------------------------------------------------------------------------------
#include "MovieRentalShop.h"
using namespace std;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Below is the constructor that takes in
//------------------------------------------------------------------------------
MovieRentalShop::MovieRentalShop(){
    
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Below is the destructor that
//------------------------------------------------------------------------------
MovieRentalShop::~MovieRentalShop(){}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Below is the method that calls in the file for commands
//------------------------------------------------------------------------------
void MovieRentalShop::initializeCommandFile(ifstream& commandFile){
    transactionHistory.buildTransactionList(commandFile, movieList);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Below is the method that calls in the file for movies
//------------------------------------------------------------------------------
void MovieRentalShop::initializeMovieList(ifstream& moviesFile){
    movieList.buildMovieList(moviesFile);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Below is the method that calls in the file for customers
//------------------------------------------------------------------------------
void MovieRentalShop::initializeCustomerList(ifstream& customerFile){
    customerList.buildCustomerList(customerFile);
}
//------------------------------------------------------------------------------