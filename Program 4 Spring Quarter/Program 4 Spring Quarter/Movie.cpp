// This is the parent class to all movie types (Classic, Comedy, and Drama)

#include "Movie.h"

//default constructor
Movie::Movie()
{
	stock = 0;
	director = "";
	title = "";
}

//Copy Constructor
Movie::Movie(const Movie &movie)
{
	stock = movie.stock;
	director = movie.director;
	title = movie.title;
}

//constructor used for child classes
Movie::Movie(int newStock, string newDirector, string newTitle)
{
	stock = newStock;
	director = newDirector;
	title = newTitle;
}

//Constructor. Initializes all instance variables
Movie::Movie(char newType, int newStock, string newDirector, string newTitle)
{
	stock = newStock;
	director = newDirector;
	title = newTitle;
}

//Destructor
Movie::~Movie() { }

//comparison operator ==
bool Movie::operator==(const Movie & movie) const
{
	//if (typeid(movie).name() != typeid(*this).name())
		//return false;
	return (stock == movie.stock) && (director == movie.director) && (title == movie.title);
}

//comparison operator !=
bool Movie::operator!=(const Movie & movie) const
{
	//if (typeid(movie).name() != typeid(*this).name())
		//return true;
	return !((stock == movie.stock) && (director == movie.director) && (title == movie.title));
}

//Accessor methods
int Movie::getStock()
{
	return stock;
}

string Movie::getDirector()
{
	return director;
}

string Movie::getTitle()
{
	return title;
}

// Mutator methods
void Movie::setStock(int newStock)
{
	stock = newStock;
}

void Movie::setDirector(string newDirector)
{
	director = newDirector;
}

void Movie::setTitle(string newTitle)
{
	title = newTitle;
}

ostream & operator<<(ostream & out, const Movie & movie)
{
	return out << movie.stock << " " << movie.director << " " << movie.title;
}
