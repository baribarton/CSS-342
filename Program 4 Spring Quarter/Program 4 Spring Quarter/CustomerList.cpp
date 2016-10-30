//------------------------------------------------------------------------------
// CustomerList.cpp
// This class is the implementation that is used to create the Hash Table that
// is used to hold the Customer and their ID number.
//
//------------------------------------------------------------------------------
#include "CustomerList.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Constructor that sets the linked list to the table size and the length of the
// hash table to the table size.
//------------------------------------------------------------------------------
CustomerList::CustomerList(){ //constructor
    array = new LinkedList[DEFAULT_TABLE_SIZE];
    length = DEFAULT_TABLE_SIZE;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Destructor that deletes the array of customers
//------------------------------------------------------------------------------

CustomerList::~CustomerList(){ //destructor
    delete[] array;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// This gets the information from the txt file with customer information.
//------------------------------------------------------------------------------
void CustomerList::buildCustomerList(istream& inputfile){
    int customerID = 0;
    string customerName = "";
    
    for (;;) {
        inputfile >> customerID >> customerName;
        if (inputfile.eof()){
            break;
        }
    
        if (customerID == 0 || customerName == ""){
            break;
        }
    }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// This is the hash function that will be used to determine the index that each
// key will be stored in.
//------------------------------------------------------------------------------
int CustomerList::hash(string keyItem){
    int number = 0;
    for (int i = 0; i < keyItem.length(); i++){
        number += keyItem[i];
    }
    return (keyItem.length() * number) % length;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// This is the insert function that will insert a new item at their unique index.
//------------------------------------------------------------------------------
void CustomerList::insert(CustomerData* newItem){
    int index = hash(newItem->key); //used to get the index
    array[index].insert(newItem);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// This is the remove function that will take out an item that is being passed
// through. This function will just return a boolean to show that the iteam is
// removed or not.
//------------------------------------------------------------------------------
bool CustomerList::remove(string keyItem){
    int index = hash(keyItem); //used to get the index
    return array[index].remove(keyItem);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// This function returns which customer is at a certain key that is being passed
// through the parameters.
//------------------------------------------------------------------------------
CustomerData* CustomerList::getItemByKey(string keyItem){
    int index = hash(keyItem); //used to get the index
    return array[index].getItem(keyItem);
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Prints out the hash table
//------------------------------------------------------------------------------
void CustomerList::printTable(){
    cout << "\nCustomer List:\n";
    for (int i = 0; i < length; i++){ //goes for the length of the array
        cout << "Customer " << i+1 << ": "; //i+1 since it starts counting at 1
        array[i].printList();
    }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Gets the length of the customer list.
//------------------------------------------------------------------------------
int CustomerList::getLength(){
    return length;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Gets how many items are in the Customer List
//------------------------------------------------------------------------------
int CustomerList::getNumberofItems(){
    int itemCount = 0;
    for (int i = 0; i < length; i++){ //goes for length of the customer list
        itemCount += array[i].getLength();
    }
    return itemCount;
}
//------------------------------------------------------------------------------