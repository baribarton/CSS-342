#include "nodedata.h"
#include <limits.h>
class GraphM
{
public:

	//default constructor
	GraphM();

	//builds up graph node information and adjacency matrix of edges between each node reading from a data file
	void buildGraph(ifstream & inFile);

	//find the shortest path between every node to every other node in the graph, i.e., TableType T is updated with shortest path information
	void findShortestPath();

	//uses couts to demonstrate that the algorithm works properly
	void displayAll();

	// uses couts to display the shortest distance with path info between the fromNode to toNode
	void displayNodeInfo(int fromNode, int toNode);

private:

	//uses dijkstra's algorithm to find the shortest path from a source node to each other node
	void dijkstra(int source);

	// inserts an edge into graph between two given nodes
	void insertEdge(int fromNode, int toNode, int edge);

	//removes an edge between two given nodes
	void removeEdge(int fromNode, int toNode);
	
	//returns the index of the element with the least distance
	int minDistance(int index);

	void findPath(int source, int destination);

	void getPathData(int source, int destination);

	static const int MAXNODES = 100;		// maximum number of nodes

	NodeData data[MAXNODES];              // data for graph nodes

	int C[MAXNODES][MAXNODES];            // Cost array, the adjacency matrix

	int size;                             // number of nodes in the graph

	struct TableType {

		bool visited;          // whether node has been visited

		int dist;              // shortest distance from source known so far

		int path;              // previous node in path of min dist

	};

	TableType T[MAXNODES][MAXNODES];      // stores visited, distance, path
};