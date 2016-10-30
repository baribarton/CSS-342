//------------------------------------------------------------------------------
//
// This is a CustomerList class that will implement the Hash Table that is used
// to hold the Customers and their ID numbers.
//
//------------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <vector>
#include "LinkedList.h"
using namespace std;
//------------------------------------------------------------------------------
class CustomerList
{
    const static int DEFAULT_TABLE_SIZE = 9999; //sets the length of the table
    
public:
	CustomerList(); //constructor
    ~CustomerList(); //destructor
    void buildCustomerList(istream& inputfile); //inputs the file
    
    void insert(CustomerData* newItem); //inserts new node
    bool remove(string keyItem); //removes node
    
    int getLength(); //gets the length
    int getNumberofItems(); //gets how many items are in the table
    
    CustomerData* getItemByKey(string keyItem); //gets an item by key
    void printTable(); //prints the table out

private:
    LinkedList* array; //sets an array of linked list
    int length; //sets a lenght
    int hash(string keyItem); //for the has function
   
};