// This is a subclass of the Movie class. This is only used for 
// Drama movies and includes the year released of the movie
#include <string>
#include "Movie.h"
using namespace std;

#ifndef Drama_h
#define Drama_h

class Drama : public Movie
{
public:
	//default constructor. Inherits from the Movie default constructor
	Drama();

	//Constructor. Initializes all instance variables and inherits from a Movie constructor
	Drama(int newStock, string newDirector, string newTitle, int releasedYear);

	//Destructor
	virtual ~Drama();

	//Accessor Method: ReleasedYear
	int getReleasedYear();

	//Mutator Method: Released Year
	void setReleasedYear(int year);

	//comparison operators
	virtual bool operator==(const Movie & movie) const;
	virtual bool operator!=(const Movie & movie) const;
private:
	int releasedYear;
};

#endif