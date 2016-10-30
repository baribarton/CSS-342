//------------------------------------------------------------------------------
// The .h file used for the Linked List implementation
//
//------------------------------------------------------------------------------
#ifndef LinkedList_h
#define LinkedList_h
#include <iostream>
#include <string>
using namespace std;
//------------------------------------------------------------------------------
// The struct of Customer Data that is used to store what information will be in
// node for the Customer
//------------------------------------------------------------------------------
struct CustomerData {
    string key;
    CustomerData *next;
};
//------------------------------------------------------------------------------

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    
    void insert(CustomerData *newData);
    bool remove(string keyItem);
    CustomerData* getItem(string keyItem);
    int getLength();
    
    void printList();
    
private:
    CustomerData *head;
    int length;
};


#endif /* LinkedList_hpp */