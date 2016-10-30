//
// classic.h
// This is the .h file for the classic movie class. This class is only 
//used for Classic movies and will inherit from the Movie parent class.
// it includes a major actor and release date
// Program4
//

#ifndef Classic_h
#define Classic_h

#include <string>
#include "Movie.h"
#include <iostream>
using namespace std;

class Classic :public Movie
{
public:
	//default constructor. Inherits from the Movie default constructor
	Classic();

	//Constructor. Initializes all instance variables and inherits from a Movie constructor
	Classic(int newStock, string newDirector, string newTitle, string newDate, string newActor);

	//Destructor
	virtual ~Classic();

	//comparison operators
	virtual bool operator==(const Movie & movie) const;
	virtual bool operator!=(const Movie & movie) const;

	friend ostream& operator<<(ostream &out, const Classic &classic);

	//Accessor Methods: majorActor and releasedDate
	string getMajorActor();
	string getReleaseDate();

	//Mutator Methods: majorActor and releasedDate
	void setMajorActor(string actor);
	void setReleaseDate(string date);

private:
	string majorActor;
	string releaseDate;
};

#endif