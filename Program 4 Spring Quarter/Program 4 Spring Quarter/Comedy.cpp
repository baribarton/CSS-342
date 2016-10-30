// This is a subclass of the Movie class. This is only used for 
//Comedy movies and includes the year released of the movie

#include "Comedy.h"

//default constructor. Inherits from the Movie default constructor
Comedy::Comedy() : Movie()
{
	releasedYear = 0;
}

//Constructor. Initializes all instance variables and inherits from a Movie constructor
Comedy::Comedy(int newStock, string newDirector, string newTitle, int newYear) : Movie(newStock, newDirector, newTitle)
{
	releasedYear = newYear;
}

//Destructor
Comedy::~Comedy() { }

ostream& operator<<(ostream &out, const Comedy &comedy) {
	return out /*<< comedy.stock << comedy.director << comedy.title << comedy.getReleasedYear()*/;
}

//Accessor Method: ReleasedYear
int Comedy::getReleasedYear()
{
	return releasedYear;
}

//Mutator Method: ReleasedYear
void Comedy::setReleasedYear(int year)
{
	releasedYear = year;
}

//comparison operator ==
bool Comedy::operator==(const Movie & movie) const
{
	const Comedy &comedy = static_cast<const Comedy &>(movie);
	return Movie::operator==(comedy) && releasedYear == comedy.releasedYear;
}

//comparison operator !=
bool Comedy::operator!=(const Movie & movie) const
{
	const Comedy &comedy = static_cast<const Comedy &>(movie);
	return Movie::operator!=(comedy) && releasedYear != comedy.releasedYear;
}