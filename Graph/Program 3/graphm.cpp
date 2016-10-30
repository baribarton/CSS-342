#include "graphm.h"
#include <iomanip>

//default constructor
GraphM::GraphM()
{
	for (int i = 0; i < MAXNODES; i++) {

		//initializes data array with default NodeData constructor
		data[i] = NodeData();

		for (int j = 0; j < MAXNODES; j++) {

			//initializes all cost adjacency matrix values to NULL
			C[i][j] = INT_MAX;

			//T is initialized to sets all dist to "infinity", sets all visited to false, and sets all path to 0
			T[i][j].visited = false;
			T[i][j].dist = INT_MAX;
			T[i][j].path = 0;
		}
	}
	size = 0;
}

//builds up graph node information and adjacency matrix of edges between each node reading from a data file.
void GraphM::buildGraph(ifstream & inFile)
{
	int nodes = 0;
	inFile >> nodes;

	size = nodes;

	string s = "";
	getline(inFile, s);		//garbage input

	if (size > 0) {

		//reads and assigns nodes
		for (int i = 0; i < nodes; i++) {
			getline(inFile, s);
			data[i] = NodeData(s);
		}

		int fromNode, toNode, edge;
		fromNode = toNode = edge = 1;	//initialization

		//reads and assigns edge values
		for (;;) {
			inFile >> fromNode >> toNode >> edge;

			if (fromNode == 0)
				return;

			insertEdge(fromNode, toNode, edge);
		}
	}
}

//find the shortest path between every node to every other node in the graph, i.e., 
//TableType T is updated with shortest path information
void GraphM::findShortestPath()
{
	for (int source = 1; source <= size; source++) {
		dijkstra(source);
	}
}

//uses dijkstra's algorithm to find the shortest path from a source to each other node
void GraphM::dijkstra(int source) {

	// distance of source vertex from itself is always 0
	T[source][source].dist = 0;

	for (int i = 1; i <= size; i++)
	{
		// find minimum distance vertex from the set of vertices not
		// yet visited. u is always equal to source in first iteration.
		int u = minDistance(source);

		// mark the picked vertex as visited
		T[source][u].visited = true;

		// update distance of adjacent vertices of chosen vertex.
		for (int w = 1; w <= size; w++) {

			// update distance only if is not visited, there is an edge from 
			// u to w, and total weight of path from source to w through u is 
			// smaller than the current distance
			if (!T[source][w].visited && (C[u][w] != INT_MAX)) {

				//prevents integer overflow
				int otherDistance = T[source][u].dist + C[u][w];
				if (otherDistance < 0) {
					otherDistance = INT_MAX;
				}

				//sets the distance and path if it's a smaller distance
				if (otherDistance < T[source][w].dist) {
					T[source][w].dist = otherDistance;
					T[source][w].path = u;
				}
			}
		}
	}
}

//finds the min distance from a source node to each other node
int GraphM::minDistance(int index)
{
	// Initialize min value
	int min = INT_MAX, minIndex = 1;

	for (int i = 1; i <= size; i++) {

		//sets min as the new smallest value if found
		if (!T[index][i].visited && T[index][i].dist < min) {
			min = T[index][i].dist;
			minIndex = i;
		}
	}
	return minIndex;
}

//displays all node data, dijkstra's algorithm results, and the shortest paths
void GraphM::displayAll() {
	if (size > 0) {
		cout << "Description";
		cout << setw(20) << "From Node";
		cout << setw(20) << "To Node";
		cout << setw(20) << "Dijkstra's";
		cout << setw(12) << "Path" << endl;
	}
	// i = from node
	for (int i = 1; i <= size; i++) {

		cout << data[i - 1] << endl;

		//j = to node
		for (int j = 1; j <= size; j++) {
			if (i != j) {
				cout << setw(27) << i;
				cout << setw(21) << j;

				//if there is a path
				if (T[i][j].dist != INT_MAX) {
					cout << setw(20) << T[i][j].dist;
					cout << setw(12);
					findPath(i, j);
					cout << j << endl;
				}
				else {
					cout << setw(20) << "----" << endl;
				}
			}
		}
	}
}

//finds the shortest path that was traveled using recursion
void GraphM::findPath(int source, int destination) {
	if (destination == source)
		return;

	//when the path is not 0, call this method again
	if (T[source][destination].path != 0) {
		findPath(source, T[source][destination].path);
		cout << T[source][destination].path << " ";
	}
}

//uses couts to display the shortest distance with path info between the fromNode to toNode
void GraphM::displayNodeInfo(int fromNode, int toNode) {
	cout << fromNode << "    " << toNode << "    ";
	
	//if the path exists then find it
	if (T[fromNode][toNode].dist != INT_MAX) {
		cout << T[fromNode][toNode].dist << "    ";
		findPath(fromNode, toNode);
		cout << toNode;
	}
	else {
		cout << "----";
	}

	//if the path exists display the name of the source
	if (T[fromNode][toNode].dist != INT_MAX) {
		getPathData(fromNode, toNode);
		cout << data[toNode - 1];
	}

	cout << endl << endl;
}

//finds the shortest path that was traveled using recursion
void GraphM::getPathData(int source, int destination) {
	if (destination == source) {
		cout << endl;
		return;
	}

	//if the path is not 0 call this method again
	if (T[source][destination].path != 0) {
		getPathData(source, T[source][destination].path);
		cout << data[T[source][destination].path - 1] << endl;
	}
}

//inserts an edge
void GraphM::insertEdge(int fromNode, int toNode, int edge)
{
	C[fromNode][toNode] = edge;
}

//removes an edge by setting it to the max int value
void GraphM::removeEdge(int fromNode, int toNode)
{
	C[fromNode][toNode] = INT_MAX;
}
