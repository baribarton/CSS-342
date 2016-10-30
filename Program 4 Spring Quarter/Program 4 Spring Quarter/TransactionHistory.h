#include "Transaction.h"
#include <vector>
#include "MovieList.h"
#include <stdlib.h> 

using namespace std;
class TransactionHistory
{
public:
	const static int MAX_SIZE = 9999;
	TransactionHistory();
	virtual ~TransactionHistory();

	//reads from a correctly formatted file and sotres the information into transaction objects
	void buildTransactionList(ifstream &inputFile, MovieList movieList);

	//use hash table here to store all transactions that relates to the customer
	void createHashingFunction(int key, Transaction value);
	void addToHistory(Transaction transaction);
	void printHistory(int id);
private:
	//vector <Transaction> transactionHistory[];	//array of vectors of Transactions
	Transaction transactionHistory[][10];
	//reads a line of data from a correctly formatted file
	bool readLine(Transaction &transaction, int id, ifstream &inputFile, MovieList movieList);

	//searches for a comedy or drama movie. Returns the movie if found
	Movie findMovie(string title, char movieType, int year, MovieList movieList);

	//searches for a classic movie. Returns the movie if found
	Movie findClassicMovie(string title, string actor, MovieList movieList);
};