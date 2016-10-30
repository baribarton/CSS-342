//Driver class. Starts the program

#include "MovieList.h"
#include "Movie.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"
#include "Transaction.h"
#include "Borrow.h"
#include "Return.h"
#include "TransactionHistory.h"

#include <iostream>

using namespace std;

void testMovies() {
	Comedy comedy(5, "a comedy director", "Comedy", 5);
	cout << "Stock: " << comedy.getStock() << "     Director: " << comedy.getDirector() << "    Title: " << comedy.getTitle() << "      Year: " << comedy.getReleasedYear();

	Drama drama(15, "a drama director", "drama title", 15);
	cout << endl << endl << "Stock: " << drama.getStock() << "    Director: " << drama.getDirector() << "    Title: " << drama.getTitle() << "      Year: " << drama.getReleasedYear();

	Classic classic(25, "a classic director", "Classic", "a classic year", "a classic actor");
	cout << endl << endl << "Stock: " << classic.getStock() << "    Director: " << classic.getDirector() << "    Title: " << classic.getTitle() << "      Year: " << classic.getReleaseDate();

	Classic classic2(15, "a drama director", "drama title", "classic2 year", "classic2 actor");
	cout << endl;

	cout << "Classic == Drama?  " << (classic == drama) << endl;
	cout << "Drama == Classic2?  " << (drama == classic2) << endl;
	cout << "Comedy == Drama?  " << (comedy == drama) << endl;
	cout << "Comedy == Comedy?  " << (comedy == comedy) << endl;

	//cout << (typeid(comedy).name() == typeid(comedy).name()) << endl;
}

void testTransactionHistory(ifstream &inFile, MovieList list) {
	TransactionHistory transHist;
	transHist.buildTransactionList(inFile, list);
}

void testMovieList() {
	MovieList list;

	// creates file object infile and opens it
	ifstream inFile("data4movies.txt");
	if (!inFile) {
		cout << "File could not be opened." << endl;
		return;
	}
	list.buildMovieList(inFile);
	list.printInventory();

	ifstream in("data4commands.txt");
	if (!in) {
		cout << "File could not be opened." << endl;
		return;
	}
	cout << endl << endl << "TESTING TRANSACTION HISTORY" << endl << endl;
	testTransactionHistory(in, list);
}

void testTransactions() {
	Comedy comedy;
	comedy.setTitle("Jabari Barton");
	comedy.setStock(10);

	Borrow borrow;
	borrow.setMovie(comedy);
	borrow.processTransaction();
	cout << comedy.getStock() << endl;

	borrow.processTransaction();
	cout << comedy.getStock() << endl;

	Return returnMovie;
	returnMovie.processTransaction();
	cout << comedy.getStock() << endl;
}

int main() {
	testMovies();
	testMovieList();
	testTransactions();
	return 0;
}