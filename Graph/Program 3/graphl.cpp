#include "graphl.h"
#include <iomanip>
#include <stack>

//cons
GraphL::GraphL()
{
	size = 0;
}

//destructor
GraphL::~GraphL()
{
	for (int i = 1; i < size + 1; i++) {
		while (graphNodes[i].edgeHead != NULL) {

			EdgeNode *tempNode = graphNodes[i].edgeHead;
			
			//make head = to the next node
			graphNodes[i].edgeHead = tempNode->nextEdge;

			delete tempNode;
			tempNode = NULL;
		}

		delete graphNodes[i].data;
		graphNodes[i].data = NULL;
	}

	delete[] graphNodes;
	graphNodes = NULL;

	size = 0;
}

void GraphL::buildGraph(ifstream & inFile)
{
	int nodes = 0;
	inFile >> nodes;

	size = nodes;

	string s = "";
	getline(inFile, s);		//garbage input

	graphNodes = new GraphNode[size + 1];

	//sets the node data
	for (int i = 1; i < size + 1; i++) {
		graphNodes[i].data = new NodeData;
		graphNodes[i].data->setData(inFile);
		graphNodes[i].edgeHead = NULL;
		graphNodes[i].visited = false;
	}

	if (size > 0) {

		int fromNode, toNode;
		fromNode = toNode = 1;	//initialization

		//reads and assigns edge values
		for (;;) {
			inFile >> fromNode >> toNode;

			if (fromNode == 0)
				return;

			insert(fromNode, toNode);
		}
	}
}

//builds up graph node information and adjacency list of edges between each node reading from a data file.
void GraphL::displayGraph()
{
	cout << "Graph:" << endl << endl;

	for (int i = 1; i < size + 1; i++) {
		cout << "Node " << i << " " << setw(30) << *graphNodes[i].data << endl;

		EdgeNode *tempNode = graphNodes[i].edgeHead;

		//prints each edge
		while (tempNode != NULL) {
			cout << setw(10) << "Edge ";
			cout << i << " " << tempNode->adjGraphNode << endl;

			tempNode = tempNode->nextEdge;
		}

		cout << endl;

		tempNode = NULL;
		delete tempNode;
	}
}

void GraphL::depthFirstSearch()
{
	EdgeNode *tempNode = graphNodes[1].edgeHead;

	stack<int> dfs;

	cout << endl << "Depth-first ordering: 1 ";

	dfs.push(1);
	graphNodes[1].visited = true;

	while (!allVisted()) {
		while (tempNode != NULL) {

			//if the node has not been visited then push it to the stack
			if (!graphNodes[tempNode->adjGraphNode].visited) {
				dfs.push(tempNode->adjGraphNode);
				graphNodes[tempNode->adjGraphNode].visited = true;

				cout << tempNode->adjGraphNode << " ";

				tempNode = graphNodes[tempNode->adjGraphNode].edgeHead;
			}
			else {
				tempNode = tempNode->nextEdge;
			}
		}

		//pop when stack is empty
		if (!dfs.empty()) {
			dfs.pop();
			tempNode = graphNodes[dfs.top()].edgeHead;
		}
	}

	tempNode = NULL;
	delete tempNode;

	cout << endl << endl;
}

//checks to see if each node has been visted
bool GraphL::allVisted() {
	EdgeNode *tempNode = graphNodes[1].edgeHead;

	//return false if one is not visted
	for (int i = 1; i < size + 1; i++) {
		if (!graphNodes[i].visited)
			return false;
	}

	tempNode = NULL;
	delete tempNode;

	return true;
}

//inserts a node at head
void GraphL::insert(int fromNode, int toNode) {
	EdgeNode *newNode = new EdgeNode;
	newNode->adjGraphNode = toNode;

	//if it is empty then set the next edge to NULL
	if (graphNodes[fromNode].edgeHead == NULL) {
		newNode->nextEdge = NULL;
	}
	//if it is not empty then move the current head to next
	else {
		newNode->nextEdge = graphNodes[fromNode].edgeHead;
	}

	graphNodes[fromNode].edgeHead = newNode;
}