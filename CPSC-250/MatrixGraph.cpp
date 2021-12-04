/*
	John Winward
	12/4/21
	CPSC 250
	Hands-On Exercise 10
	Part 1: Adjacency Matrix Graph
*/
#include <iostream>

using namespace std;

struct Edge
{
	int vertex1;
	int vertex2;
};

void insertEdge(Edge e, int adjMat[4][4]);
void printGraph(int adjMat[4][4]);

int main() {
	//create empty graph
	int graph[4][4];
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			graph[i][j] = 0;

	//initialize edges to add to graph
	Edge a = { 1, 2 };
	Edge b = { 1, 4 };
	Edge c = { 2, 1 };
	Edge d = { 2, 3 };
	Edge e = { 3, 2 };
	Edge f = { 4, 1 };

	//insert edges into graph
	insertEdge(a, graph);
	insertEdge(b, graph);
	insertEdge(c, graph);
	insertEdge(d, graph);
	insertEdge(e, graph);
	insertEdge(f, graph);

	printGraph(graph);

	system("pause");
	return 0;
}

//inserts an edge between two verticies in an adjacency matrix graph
void insertEdge(Edge e, int adjMat[4][4]) {
	adjMat[e.vertex1 - 1][e.vertex2 - 1] = 1;
}

//prints the adjacency matrix to console
void printGraph(int adjMat[4][4]) {
	cout << "   1   2   3   4\n";
	for (int i = 1; i <= 4; i++) {
		cout << i << " ";
		for (int j = 0; j < 4; j++) {
			cout << "[" << adjMat[i - 1][j] << "] ";
		}
		cout << endl;
	}
}