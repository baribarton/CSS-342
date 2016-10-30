/*
Author: Jabari Barton
CSS 342

this class implements a linked list for an MTF list
*/
#include "MtfList.h"
using namespace std;

template<class Object>

/*
finds the deisred object that is passed as reference.
returns -1 if the object is not found*/
int MtfList<Object>::find(const Object &obj) {
	DListNode<Object> *head = DList<Object>::header;
	DListNode<Object> *current = DList<Object>::header->next;

	for (; current != NULL && current->item != obj; current = current->next) {
		++DList<Object>::cost;
	}

	// if item is not found
	if (current == NULL) {
		return -1;
	}
	// don't do anything if the item is already on the top
	if (current == head) {
		return 0;
	}

	//item is removed from current location
	current->prev->next = current->next;
	if (current->next != NULL) {
		current->next->prev = current->prev;
	}

	//item is put after header
	current->next = head->next;
	current->prev = head;

	head->next->prev = current;
	head->next = current;

	return 0;
}