// This class is only
// used for Classic movies and will inherit from the Movie parent class.
// it includes a major actor and release date

#include "Classic.h"

//default constructor. Inherits from the Movie default constructor
Classic::Classic() : Movie()
{
	majorActor = "";
	releaseDate = "";
}

//Constructor. Initializes all instance variables and inherits from a Movie constructor
Classic::Classic(int newStock, string newDirector, string newTitle, string newDate, string newActor) : Movie(newStock, newDirector, newTitle)
{
	releaseDate = newDate;
	majorActor = newActor;
}

//Destructor
Classic::~Classic() { }

//comparison operator ==
bool Classic::operator==(const Movie & movie) const
{
	const Classic &classic = static_cast<const Classic &>(movie);
	return Movie::operator==(classic) && majorActor == classic.majorActor;
}

//comparison operator !=
bool Classic::operator!=(const Movie & movie) const
{
	const Classic &classic = static_cast<const Classic &>(movie);
	return Movie::operator!=(classic) && majorActor != classic.majorActor;
}

ostream& operator<<(ostream &out, const Classic &classic) {
	return out << "Stock: " << classic.stock <<
		"     Director: " << classic.director <<
		"    Title: " << classic.title << 
		"    Major Actor: " << classic.majorActor <<
		"    Release Date: " << classic.releaseDate << endl;
}

//Accessor Methods: majorActor and releasedDate
string Classic::getMajorActor()
{
	return majorActor;
}

string Classic::getReleaseDate()
{
	return releaseDate;
}

//Mutator Methods: majorActor and releasedDate
void Classic::setMajorActor(string actor)
{
	majorActor = actor;
}

void Classic::setReleaseDate(string date)
{
	releaseDate = date;
}