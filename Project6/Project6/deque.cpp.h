template <class Object>
Deque<Object>::Deque() {                          // the constructor
	front = back = NULL;
}

template <class Object>
Deque<Object>::Deque(const Deque &rhs) {         // the copy constructor
	front = back = NULL;
	*this = rhs;
}

template <class Object>
Deque<Object>::~Deque() {                         // the destructor
	clear();
}

template <class Object>
bool Deque<Object>::isEmpty() const {             // check if a deque is empty
	return front == NULL;
}

template <class Object>
int Deque<Object>::size() const {                 // retrieves # deque nodes
	int i = 0;
	for (DequeNode *ptr = front; ptr != NULL; ptr = ptr->next) // traverse que
		++i;

	return i;
}

template <class Object>
const Object &Deque<Object>::getFront() const {   // retrieve the front node
	if (isEmpty())
		throw "empty queue";
	return front->item;
}

template <class Object>
const Object &Deque<Object>::getBack() const {    // retrieve the tail node
	if (isEmpty())
		throw "empty queue";
	return back->item;
}

template <class Object>
void Deque<Object>::clear() {          // clean up all entries.
	while (!isEmpty())                 // dequeue till the queue gets empty.
		removeFront();
}

template <class Object>
void Deque<Object>::addFront(const Object &obj) {// add a new node to  front
	DequeNode *newPointer = new DequeNode();
	newPointer->item = obj;

	if (isEmpty())
		front = newPointer;

	newPointer->next = front;
	newPointer->prev = NULL;

	if (front != NULL)
		front->prev = newPointer;
	front = newPointer;
}

template <class Object>
void Deque<Object>::addBack(const Object &obj) { // add a new node to tail
	DequeNode *newPointer = new DequeNode();
	newPointer->item = obj;

	//the new pointer becomes the front when the list is empty
	if (isEmpty())
		front = newPointer;

	//arranges links
	newPointer->prev = back;
	newPointer->next = NULL;

	//determines where back is
	if (back != NULL)
		back->next = newPointer;
	back = newPointer;
}

template <class Object>
Object Deque<Object>::removeFront() {  // remove the front node

	//prevents removal from empty list
	if (isEmpty())
		throw "List is empty";

	Object oldItem = getFront();

	//if there is only one item in the list
	if (front == back) {
		front = NULL;
		back = NULL;
	}
	else {
		front = front->next;
		front->prev = NULL;
	}
	return oldItem;
}

template <class Object>
Object Deque<Object>::removeBack() {   // remove the tail node
	if (isEmpty())
		throw "List is empty";

	Object oldItem = getBack();

	//if there is 1 item in the list
	if (front == back) {
		front = NULL;
		back = NULL;
	}
	else {

		//changes links
		back = back->prev;
		back->next = NULL;
	}
	return oldItem;
}

template <class Object>
const Deque<Object> &Deque<Object>::operator=(const Deque &rhs) { // assign
	if (this != &rhs) { // avoid self assignment
		clear();
		for (DequeNode *rptr = rhs.front; rptr != NULL; rptr = rptr->next)
			addBack(rptr->item);
	}
	return *this;
}