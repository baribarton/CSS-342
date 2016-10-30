// This is a subclass of the Movie class. This is only used for 
//Comedy movies and includes the year released of the movie

#ifndef Comedy_h
#define Comedy_h

#include <stdio.h>
#include <string>
#include "Movie.h"
using namespace std;

class Comedy : public Movie
{
public:

	//default constructor. Inherits from the Movie default constructor
	Comedy();

	//Constructor. Initializes all instance variables and inherits from a Movie constructor
	Comedy(int newStock, string newDirector, string newTitle, int newYear);

	//Destructor
	virtual ~Comedy();

	//Accessor Method: ReleasedYear
	int getReleasedYear();

	//Mutator Method: ReleasedYear
	void setReleasedYear(int year);

	//comparison operators
	virtual bool operator==(const Movie & movie) const;
	virtual bool operator!=(const Movie & movie) const;
private:
	int releasedYear;
};

#endif