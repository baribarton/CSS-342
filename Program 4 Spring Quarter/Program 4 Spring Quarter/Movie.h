// This is the parent class to all movie types (Classic, Comedy, and Drama)
#include <string>
#include <iostream>

#ifndef Movie_h
#define Movie_h

using namespace std;

class Movie
{
	friend ostream& operator<<(ostream &out, const Movie &movie);
public:

	//Default constructor
	Movie();

	//Copy Constructor
	Movie(const Movie &movie);

	//Constructor used for child classes
	Movie(int newStock, string newDirector, string newTitle);

	//Constructor. Initializes all instance variables
	Movie(char type, int stock, string director, string title);

	//Destructor
	virtual ~Movie();

	//Comparison operators
	virtual bool operator==(const Movie & movie) const;
	virtual bool operator!=(const Movie & movie) const;

	//Accessor and Mutator methods: movieType, stock, director, and title

	//Accessor methods
	char getMovieType();
	int getStock();
	string getDirector();
	string getTitle();

	//Mutator methods
	void setMovieType(char movieType);
	void setStock(int stock);
	void setDirector(string director);
	void setTitle(string title);

protected:
	int stock;
	string director;
	string title;
};

#endif