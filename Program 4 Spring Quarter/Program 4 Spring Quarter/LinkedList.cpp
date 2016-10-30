//------------------------------------------------------------------------------
// LinkedList.cpp
// This program implements a Linked List that will be used to store data in the
// Hash table which is used to store the Customer information.
// Program 4
//
//------------------------------------------------------------------------------
#include "LinkedList.h"
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// This is the constructor for the linked list. It creates a Linkied List of
// customerData and sets the length to 0 and rest of the list to NULL.
//------------------------------------------------------------------------------
LinkedList::LinkedList(){
    head = new CustomerData; //creates a LL for CustomerData
    head->next = NULL; //the next node to NULL
    length = 0; //sets length to 0
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Destructor for the linked list. It will delete the first node from the list
// until there are no nodes left.
//------------------------------------------------------------------------------
LinkedList::~LinkedList(){
    CustomerData *first = head;
    CustomerData *next = head;
    
    //this while statement will be deleting from the first node
    while(next){ //goes for as long as there is a next node
        first = next; //sets the first node to the next one
        next = first->next; //and next to the node after first
        
        //so long as there is a next node,
        if (next){
            first = NULL; //sets the first to NULL
            delete first; //deletes the pointer
        }
    }
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Function that gets the length of the linked list
//------------------------------------------------------------------------------
int LinkedList::getLength(){
    return length;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Inserts a new node in the first spot on the linked list.
//------------------------------------------------------------------------------
void LinkedList::insert(CustomerData* newData){
    if (!head->next){ //checks if there is a node after the head spot
        head->next = newData; //sets next to the new data
        length++; // adds to the length
        return;
    }
    
    //sets customer data current and temp to head
    CustomerData* current = head;
    CustomerData* temp = head;
    
    //goes as temp has a node
    while (temp){
        current = temp;
        temp = current->next;
    }
    
    //sets the next node to newData
    current->next = newData;
    newData->next = NULL; //sets the next one to null
    length++; //adds to the length
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// The remove function that will remove the certain node for the based on the
// key that is being passed through in the parameter.
//------------------------------------------------------------------------------
bool LinkedList::remove(string keyItem){
    if (!head->next){ //checks if the list is empty ot not
        return false;
    }
    
    //sets current and temp to head
    CustomerData* current = head;
    CustomerData* temp = head;
    
    //checks for as long as temp exists
    while (temp){
        //checks if the current node is equal to the key being passed through
        if (temp->key == keyItem){
            current->next = temp->next; //sets the current next to temp next
            
            //deletes the temp node
            temp = NULL;
            delete temp;
            
            //decreases the length
            length--;
            
            return true; //returns true
        }
        
        //sets current to temp and temp to current's next
        current = temp;
        temp = current->next;
    }
    return false; //returns false
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Gets the item that is at the key that you are passing through the parameter
//------------------------------------------------------------------------------
CustomerData* LinkedList::getItem(string keyItem){
    //sets the current and temp to head
    CustomerData* current = head;
    CustomerData* temp = head;
    
    //goes for as long as temp has an item
    while (temp){
        current = temp; //sets current to temp
        
        //checks if current doesn't equal head and if the current key is equal
        // to the key item being passed through
        if ((current != head) && (current->key == keyItem)){
            return current;
        }
        
        //sets temp to the next after current
        temp = current->next;
    }
    // if there is no item then return null
    return NULL;
}
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// Prints out the Linked List within the Hash Table
//------------------------------------------------------------------------------
void LinkedList::printList(){
    if (length == 0){
        cout << "\n{ }\n";
        return;
    }
    
    CustomerData* current = head;
    CustomerData* temp = head;
    
    cout << "\n{ ";
    
    while (temp){
        current = temp;
        
        if (current != head){
            cout << current->key;
            if (current->next){
                cout << ", ";
            } else {
                cout << " ";
            }
        }
        
        temp = current->next;
    }
    
    cout << "}\n ";
}
//------------------------------------------------------------------------------