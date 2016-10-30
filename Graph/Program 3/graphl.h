#include "nodedata.h"
class GraphL
{
public:
	//constructor
	GraphL();

	//destructor
	~GraphL();

	//builds up graph node information and adjacency list of edges between each node reading from a data file
	void buildGraph(ifstream & inFile);

	//Displays each node information and edge in the graph
	void displayGraph();

	//Makes a depth-first search and displays each node in depth-first order
	void depthFirstSearch();

private:

	struct EdgeNode;      // forward reference for the compiler

	struct GraphNode {    // structs used for simplicity, use classes if desired

		EdgeNode* edgeHead; // head of the list of edges

		NodeData* data;     // data information about each node

		bool visited;		//if the node has been visited
	};

	struct EdgeNode {

		int adjGraphNode;  // subscript of the adjacent graph node
		
		EdgeNode* nextEdge;	//the next node

	};

	int size;	//amount of nodes

	GraphNode *graphNodes;	// array of GraphNodes

	//inserts a node at head
	void insert(int fromNode, int toNode);

	//checks to see if each node has been visted
	bool allVisted();
};