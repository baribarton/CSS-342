//Jabari Barton
//this class is used for binary tree operations

#include "bintree.h"

//default constructor
//post-condition: initializes root to NULL
BinTree::BinTree()
{
	root = NULL;
}

//copy constructor
//uses the assignment operator
BinTree::BinTree(const BinTree &otherTree)
{
	this->root = NULL;
	*this = otherTree;
}

//destructor
BinTree::~BinTree()
{
	makeEmpty();
}

//assignment operator (=) overload
//calls assignmentHelper method
BinTree & BinTree::operator=(const BinTree &tree)
{
	if ((*this != tree) && (!this->isEmpty())) {
		this->makeEmpty();
	}

	BinTree::Node *temp = tree.root;

	assignmentHelper(temp);

	temp = NULL;
	delete temp;

	return *this;
}

//recursive helper method for assignment operator
void BinTree::assignmentHelper(Node *&root) {
	if (root != NULL) {
		insert(root->data);
		assignmentHelper(root->leftChild);
		assignmentHelper(root->rightChild);
	}
}

//equality operator (==) overload
//calls equalityHelper method
bool BinTree::operator==(const BinTree &other) const
{
	BinTree::Node *currentRoot = root;
	BinTree::Node *otherRoot = other.root;

	return equalityHelper(currentRoot, otherRoot);
}

//helper method for equality operator (==) overload
//recursively iterates through both trees simultaneously and compares each node
bool BinTree::equalityHelper(Node *& root, Node *& otherRoot) const {

	if (!root && !otherRoot) {
		return true;
	}
	else if ((!root && otherRoot != NULL) || (!otherRoot && root != NULL)) {
		return false;
	}
	else if (root->data != otherRoot->data) {
		return false;
	}
	else {	//if not NULL and data is ==
		return equalityHelper(root->leftChild, otherRoot->leftChild);
		return equalityHelper(root->rightChild, otherRoot->rightChild);
	}
}

//constant recursive method that finds a specific NodeData that is passed through
//only called by getHeight()
int BinTree::constRetrieve(const NodeData &key, Node *& root) const
{
	if (!root) {
		return 0;
	}
	else if (key == *root->data) {
		return getHeightHelper(root, 1);
	}
	else if (key < *root->data) {
		return constRetrieve(key, root->leftChild);
	}
	else {	//if key is > than root->data
		return constRetrieve(key, root->rightChild);
	}
}

//finds the height of the Node that is passed through
//only called by constRetrieve()
int BinTree::getHeightHelper(Node *& root, int level) const {
	int maxLevel = 1, maxLevel2 = 1;

	//height of the left side
	if (root->leftChild != NULL) {
		maxLevel = getHeightHelper(root->leftChild, level + 1);
	}
	else {
		maxLevel = level;
	}

	//height of the right side
	if (root->rightChild != NULL) {
		maxLevel2 = getHeightHelper(root->rightChild, level + 1);
	}
	else {
		maxLevel2 = level;
	}

	//finds true max height
	if (maxLevel2 > maxLevel) {
		return maxLevel2;
	}
	return maxLevel;
}

//finds the height of the NodeData if found in the current tree
//returns 0 if the NodeData is not found
int BinTree::getHeight(const NodeData &key) const
{
	BinTree::Node *temp = root;
	int height = constRetrieve(key, temp);

	temp = NULL;
	delete temp;

	return height;
}

//finds the NodeData that was passed through if it exists
//returns true if found. returns false if not found
bool BinTree::retrieve(const NodeData &key, Node *& root, NodeData *&ptr)
{
	if (!root) {
		return false;
	}
	else if (key == *root->data) {
		ptr = root->data;
		return true;
	}
	else if (key < *root->data) {
		return retrieve(key, root->leftChild, ptr);
	}
	else {
		return retrieve(key, root->rightChild, ptr);
	}
}

//calls the helper method to find the NodeData that was passed through if it exists
//initializes the 2nd parameter to an empty string ("")
bool BinTree::retrieve(const NodeData &key, NodeData *&ptr)
{
	//ptr = new NodeData("");
	return retrieve(key, root, ptr);
}

//overloads the inequality operator
bool BinTree::operator!=(const BinTree &other) const
{
	return !(*this == other);
}

//insert helper method
bool BinTree::insert(Node *&root, NodeData *newData) {
	if (root == NULL) {

		//creates new Node
		root = new Node();

		root->leftChild = NULL;
		root->rightChild = NULL;

		root->data = newData;

		newData = NULL;
		delete newData;

		return true;
	}

	// if data is already in the tree
	else if (*newData == *root->data) {
		return false;
	}
	else if (*newData < *root->data) {
		return insert(root->leftChild, newData);
	}
	else {
		return insert(root->rightChild, newData);
	}
}

//inserts a node in the tree
bool BinTree::insert(NodeData *newData)
{
	return insert(root, newData);
}

//helper method that transforms a binary tree into an inorder array
//pre-condition: there is an empty array and a binary tree
//post-condition: current tree is empty, passed array has tree nodes inorder
void BinTree::toArrayHelper(Node *& root, NodeData *array[], int &index) {
	if (!root)
		return;

	toArrayHelper(root->leftChild, array, index);
	array[index++] = root->data;
	toArrayHelper(root->rightChild, array, index);

	delete root;
	root = NULL;
}

//transforms a binary search tree into an array. calls a recursive helper method
void BinTree::bstreeToArray(NodeData *array[])
{
	int index = 0;
	toArrayHelper(this->root, array, index);
}

//helper method that transforms an array of NodeData into a binary search tree
//pre-condition: the passed array is at least partially filled with NodeData objects
//post-condition: a binary search tree is created and the passed array is empty
void BinTree::toTreeHelper(Node *& root, NodeData * array[], int low, int high)
{
	if (high < low) {
		return;
	}
	insert(array[((high + low) / 2)]);
	toTreeHelper(root->leftChild, array, low, ((high + low) / 2) - 1);
	toTreeHelper(root->rightChild, array, ((high + low) / 2) + 1, high);

	//empties array
	array[((high + low) / 2)] = NULL;
}

//transforms an array of NodeData to a binary search tree
void BinTree::arrayToBSTree(NodeData *array[])
{
	int high = 0;

	//finds the true size of the array
	for (int i = 0; i < 100; i++) {
		if (array[i] != NULL)
			high = i;
	}
	toTreeHelper(this->root, array, 0, high);
}

//returns true if the tree is empty, otherwise false
bool BinTree::isEmpty() const {
	return root == NULL;
}

//calls a recursive method to empty the current tree
void BinTree::makeEmpty() {
	makeEmptyHelper(root);
}

//recursively iterates through the tree and deletes each node
void BinTree::makeEmptyHelper(Node *& root) {
	if (root != NULL) {
		makeEmptyHelper(root->leftChild);
		makeEmptyHelper(root->rightChild);

		//root->data = NULL;
		//delete root->data;

		delete root;
		root = NULL;
	}
}

//overloads the cout operator (<<). calls a recursive helper method
ostream & operator<<(ostream &out, const BinTree &tree)
{
	BinTree::Node *temp = tree.root;

	tree.printInorder(out, temp);
	out << endl;

	temp = NULL;
	delete temp;
	
	return out;
}

//returns an ostream object that is the current tree inorder
void BinTree::printInorder(ostream & out, Node *& root) const
{
	if (!root)
		return;
	printInorder(out, root->leftChild);
	out << *root->data << " ";
	printInorder(out, root->rightChild);
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->rightChild, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->leftChild, level);
	}
}