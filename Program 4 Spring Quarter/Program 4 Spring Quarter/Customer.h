//------------------------------------------------------------------------------
//  The .h file used to create a customer in the system
//
//------------------------------------------------------------------------------
#include <string>
using namespace std;
//------------------------------------------------------------------------------
class Customer
{
public:
	Customer(); //default constructor
	Customer(int, string, string); //constructor
	~Customer(); //destructor

	int getID(); //gets the id numer
	string getName(); //gets the name
	void setID(int id); //sets the id number
	void setName(string fName, string lName); //sets the name

private:
	int id;
	string firstName;
	string lastName;
};
