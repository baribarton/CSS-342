//This class reads information from a correctly formatted file and  
//stores the information for each movie into individual vectors
#include <string>
#include <vector>
#include <fstream>

#ifndef MovieList_h
#define MovieList_h

#include "Movie.h"
#include "Drama.h"
#include "Comedy.h"
#include "Classic.h"

using namespace std;

class MovieList
{
public:
	//Default Constructor
	MovieList();

	//Destructor
	~MovieList();

	//Fills the lists with the appropriate movies from a correctly formatted file
	void buildMovieList(ifstream &inputFile);

	//Prints each movie that's in the inventory
	void printInventory();

	//searches for a specific title in either the comedy list or the drama list
	Movie findTitle(string title, char movieType, int year);

	//searches for a specific date among the classic movies
	Movie findDate(string date, string actor);
private:
	vector<Drama> dramaList;	//List of drama movies
	vector<Comedy> comedyList;	//List of comedy movies
	vector<Classic> classicList;//List of classic movies

	//reads one line from a correctly formatted file and 
	//stores the information into the correct variables
	void readLine(Movie &movie, ifstream &inputFile);
};
#endif