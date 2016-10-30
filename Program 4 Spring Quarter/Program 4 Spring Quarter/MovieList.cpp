//This class reads information from a correctly formatted file and  
//stores the information for each movie into individual vectors
#include "MovieList.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <stdlib.h> 

//Default Constructor
MovieList::MovieList() { }

//Destructor
MovieList::~MovieList() { }

//Fills the lists with the appropriate movies from a correctly formatted file
void MovieList::buildMovieList(ifstream &inputFile)
{
	string temp;	//stores the values in the line temporarily

	//while there is a next line, retrieve it
	while (getline(inputFile, temp, ',')) {
		char movieType = temp.at(0);

		switch (movieType) {
		
		//comedy movie
		case 'F':
		{
			Comedy comedy;
			readLine(comedy, inputFile);

			getline(inputFile, temp);
			comedy.setReleasedYear(atoi(temp.c_str()));

							//for testing
			//cout << "Stock: " << comedy.getStock() << 
			//	"     Director: " << comedy.getDirector() << 
			//	"    Title: " << comedy.getTitle() << 
			//	"      Year: " << comedy.getReleasedYear() << endl;

			comedyList.push_back(comedy);
			break;
		}

		//Classic movie
		case 'C':
		{
			Classic classic;
			readLine(classic, inputFile);

			string firstName, lastName;
			inputFile >> firstName >> lastName;
			classic.setMajorActor(firstName + " " + lastName);

			getline(inputFile, temp);
			classic.setReleaseDate(temp);

			//cout << classic;		//for testing

			classicList.push_back(classic);
			break;
		}

		//Drama movie
		case 'D':
		{
			Drama drama;
			readLine(drama, inputFile);

			getline(inputFile, temp);
			drama.setReleasedYear(atoi(temp.c_str()));

								//for testing
			//cout << "Stock: " << drama.getStock() << "     Director: " <<
			//	drama.getDirector() << "    Title: " << drama.getTitle() <<
			//	"      Year: " << drama.getReleasedYear() << endl;

			dramaList.push_back(drama);
			break;
		}

		//code is invalid and the line is discarded
		default:
		{
			cout << "BAD LINE: Movie Code: '" << movieType << "'" << endl;
			getline(inputFile, temp);
		}
		}
	}

	cout << endl;
}

//Prints each movie that's in the inventory
void MovieList::printInventory()
{
	//print comedy movies
	cout << "-------COMEDY-------" << endl << endl;
	for (int i = 0; i < comedyList.size(); i++) {
		cout << comedyList.at(i).getTitle() << endl;
	}

	//print classic movies
	cout << endl << "-------CLASSIC-------" << endl << endl;
	for (int i = 0; i < classicList.size(); i++) {
		cout << classicList.at(i).getTitle() << endl;
	}

	//print drama movies
	cout << endl << "-------DRAMA-------" << endl << endl;
	for (int i = 0; i < dramaList.size(); i++) {
		cout << dramaList.at(i).getTitle() << endl;
	}
}

//searches for a specific title in either the comedy list or the drama list
//returns the movie if found. If not, returns an empty movie object
Movie MovieList::findTitle(string title, char movieType, int year)
{
	//if movie is a comedy
	if (movieType == 'F') {
		for (int i = 0; i < comedyList.size(); i++) {
			if ((comedyList.at(i).getTitle().compare(title) == 0) &&
				(comedyList.at(i).getReleasedYear() == year)) {
				return comedyList.at(i);
			}
		}
	}
	//if movie is a drama
	else {
		for (int i = 0; i < dramaList.size(); i++) {
			if ((dramaList.at(i).getTitle().compare(title) == 0) &&
				(dramaList.at(i).getReleasedYear() == year)) {
				return dramaList.at(i);
			}
		}
	}
	return Movie();
}

//searches for a specific date among the classic movies
//returns the movie if found. If not, returns an empty movie object
Movie MovieList::findDate(string date, string actor)
{
	for (int i = 0; i < classicList.size(); i++) {
		if ((classicList.at(i).getReleaseDate().compare(date) == 0) &&
			(classicList.at(i).getMajorActor().compare(actor) == 0)) {
			return comedyList.at(i);
		}
	}
	return Movie();
}

//reads one line from a correctly formatted file and 
//stores the information into the correct variables
void MovieList::readLine(Movie &movie, ifstream &inputFile) {
	string temp;

	getline(inputFile, temp, ',');
	movie.setStock(atoi(temp.c_str()));

	getline(inputFile, temp, ',');
	movie.setDirector(temp);

	getline(inputFile, temp, ',');
	movie.setTitle(temp);
}