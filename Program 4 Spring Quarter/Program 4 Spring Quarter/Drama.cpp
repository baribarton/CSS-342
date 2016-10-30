// This is a subclass of the Movie class. This is only used for 
// Drama movies and includes the year released of the movie
#include "Drama.h"

//default constructor. Inherits from the Movie default constructor
Drama::Drama() : Movie()
{
	releasedYear = 0;
}

//Constructor. Initializes all instance variables and inherits from a Movie constructor
Drama::Drama(int newStock, string newDirector, string newTitle, int newYear) : Movie(newStock, newDirector, newTitle)
{
	releasedYear = newYear;
}

//Destructor
Drama::~Drama() { }

//Accessor Method: ReleasedYear
int Drama::getReleasedYear()
{
	return releasedYear;
}

//Mutator Method: ReleasedYear
void Drama::setReleasedYear(int year)
{
	releasedYear = year;
}

//comparison operator ==
bool Drama::operator==(const Movie & movie) const
{
	const Drama &drama = static_cast<const Drama &>(movie);
	return Movie::operator==(drama) && releasedYear == drama.releasedYear;
}

//comparison operator !=
bool Drama::operator!=(const Movie & movie) const
{
	const Drama &drama = static_cast<const Drama &>(movie);
	return Movie::operator!=(drama) && releasedYear != drama.releasedYear;
}