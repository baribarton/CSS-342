#include "nodedata.h"
using namespace std;

class BinTree {
	friend ostream & operator<<(ostream &, const BinTree &);

public:
	BinTree();		//default constructor
	BinTree(const BinTree &otherTree);	//copy constructor
	~BinTree();	//destructor

	//overloads the assignment operator (=) to assign one tree to another
	BinTree& operator=(const BinTree &);

	//overloads the equality and inequality operators. 
	//2 trees are equal if they have the same data and same structure
	bool operator==(const BinTree &) const;
	bool operator!=(const BinTree &) const;

	//gets the NodeData* of a given object in the tree (via pass-by-reference parameter) 
	//and reports whether the object is found (true or false)
	bool retrieve(const NodeData &, NodeData* &);

	bool insert(NodeData*);

	//find the height of a given value in the tree
	int getHeight(const NodeData &) const;

	//fills an array of Nodedata* by using an inorder traversal of the tree. Leaves the tree empty.
	void bstreeToArray(NodeData*[]);

	//builds a balanced BinTree from a sorted array of NodeData* leaving the array filled with NULLs
	void arrayToBSTree(NodeData*[]);

	// true if tree is empty, otherwise false
	bool isEmpty() const;

	// make the tree empty so isEmpty returns true
	void makeEmpty();

	// provided below, displays the tree sideways
	void displaySideways() const;

private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* leftChild;					// leftChild subtree pointer
		Node* rightChild;					// rightChild subtree pointer
	};
	Node* root;								// root of the tree

	// helper methods

	//prints tree sideways
	void sideways(Node*, int) const;
	
	//recursive helper method that inserts a node
	bool insert(Node *& root, NodeData * newData);

	//recursive helper method that prints the current tree inorder
	void printInorder(ostream &out, Node *& root) const;

	//recursive helper method that retrieves a certain Node
	bool retrieve(const NodeData &, Node *& root, NodeData *&ptr);

	//recursive helper method that gets the height of a Node
	int getHeightHelper(Node *& root, int level) const;

	//same as retrieve but const
	int constRetrieve(const NodeData &, Node *& root) const;

	//recursive helper method that assigns one tree to another
	void assignmentHelper(Node *&root);

	//recursive helper method that empties the current tree
	void makeEmptyHelper(Node *& root);

	//recursive method that returns true if the two trees are ==, otherwise false
	bool equalityHelper(Node *& root, Node *& otherRoot) const;

	//recursive helper method that makes a tree into an array
	void toArrayHelper(Node *& root, NodeData *array[], int &index);

	//recursive helper method that makes an array into a tree
	void toTreeHelper(Node *& root, NodeData *array[], int low, int high);
};
