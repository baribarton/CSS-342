#include "TransactionHistory.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include "Borrow.h"
#include "Return.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>

TransactionHistory::TransactionHistory()
{
	transactionHistory[MAX_SIZE][10] = { Transaction() };
	for (int i = 0; i < 15; i++) {	//fills the array, effectively, with 0's
		for (int j = 0; j < 10; j++) {
			transactionHistory[i][j] = Transaction();
		}
	}
	//cout << "SIZE ----------------->" << transactionHistory[0].size() << endl;
}

TransactionHistory::~TransactionHistory() { }

void TransactionHistory::buildTransactionList(ifstream &inputFile, MovieList movieList)
{
	string temp;	//stores the values in the line temporarily

	//while there is a next word, retrieve it
	while (inputFile >> temp) {
		char command = temp.at(0);

		switch (command) {

		//Inventory
		case 'I':
		{
			movieList.printInventory();
			break;
		}
		//History
		case 'H': {
			int id;
			inputFile >> id;
			printHistory(id);
			break;
		}
		//Borrow
		case 'B': {
			int id;
			inputFile >> id;
			Borrow borrow;
			if (readLine(borrow, id, inputFile, movieList)) {
				createHashingFunction(id, borrow);
			}
			borrow.processTransaction();
			break;
		}
		//Return
		case 'R': {
			int id;
			inputFile >> id;
			Return returnMovie;
			if (readLine(returnMovie, id, inputFile, movieList)) {
				createHashingFunction(id, returnMovie);
			}
			returnMovie.processTransaction();
			break;
		}
		//This is an invalid line
		default: {
			cout << "INVALIDE LINE. CODE: " << command << endl;
		}
		}
	}
}

void TransactionHistory::createHashingFunction(int customerID, Transaction value)
{
	int index = 0;

	for (int i = 0; i < 10; i++) {
		if (transactionHistory[customerID][index] == Transaction()) {
			transactionHistory[customerID][index] = value;
			break;
		}
		else {
			index++;
		}
	}
}

void TransactionHistory::addToHistory(Transaction transaction)
{

}

void TransactionHistory::printHistory(int id)
{
	int size = 0;
	for (int i = 0; i < 10; i++) {
		if (transactionHistory[id][size] == Transaction()) {
			break;
		}
		else {
			size++;
		}
	}
	cout << "HISTORY FOR CUSTOMER: " << id << endl;
	for (int i = 0; i < size; i++) {
		//cout << "SIZE: " << transactionHistory[atoi((tempID.substr(0, 2)).c_str())].size() << endl;
	//	if (transactionHistory[atoi((tempID.substr(0, 2)).c_str())].at(i) != NULL) {
			cout << transactionHistory[id][i].getMovie() << endl;
	//	}
		//else {
		//	break;
		//}
	}
	cout << endl << endl;
}

bool TransactionHistory::readLine(Transaction &transaction, int id, ifstream &inputFile, MovieList movieList) {

	transaction.setCustomerID(id);

	char mediaType;
	inputFile >> mediaType;
	transaction.setMediaType(mediaType);

	char movieType;
	inputFile >> movieType;

	string temp;
	switch (movieType) {

	//Comedy
	case 'F':
	{
		transaction.setMovie(Comedy());
	}

	//Classic
	case 'C': {
		transaction.setMovie(Classic());
	}

	//Drama
	case 'D': {
		transaction.setMovie(Drama());
	}

	//This is a bad line and must be discarded
	default: {
		getline(inputFile, temp);
		return false;		//maybe return false here and don't add the object to the list
	}
	}

	Movie movie;

	// If a classic movie
	if (movieType == 'C') {
		
		//Released date
		string month, year;
		inputFile >> month >> year;

		//first and last name of major actor
		string first, last;
		inputFile >> first >> last;

		//Finds a movie that matches the released date and major actor name
		movie = Movie(findClassicMovie(month + " " + year, first + " " + last, movieList));
	}
	else {
		//Gets the title of the movie
		getline(inputFile, temp, ',');

		int year;
		inputFile >> year;

		//finds a movie that matches the title and year
		movie = Movie(findMovie(temp, year, movieType, movieList));
	}

	//if the movie exists, set the movie. Otherwise return false
	if (movie.getTitle().compare("") == 0) {
		transaction.setMovie(movie);
	}
	else {
		return false;		//maybe return false here and don't add the object to the list
	}

	return true;
}

//searches for a specific title in either the comedy list or the drama list
//returns the movie if found. If not, returns an empty movie object
Movie TransactionHistory::findMovie(string title, char movieType, int year, MovieList movieList)
{
	return movieList.findTitle(title, movieType, year);
}

//searches for a specific date among the classic movies
//returns the movie if found. If not, returns an empty movie object
Movie TransactionHistory::findClassicMovie(string date, string actor, MovieList movieList)
{
	return movieList.findDate(date, actor);
}