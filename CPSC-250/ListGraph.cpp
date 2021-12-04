/*
	John Winward
	12/4/21
	CPSC 250
	Hands-On Exercise 10
	Part 2: Adjacency List Graph
*/
#include <iostream>

using namespace std;

struct Node
{
	int vertex;
	Node* next;
};

void printList(Node adjList[4]);

int main() {
	//create list and add edges
	Node graph[4];
	graph[0].vertex = 1;
	graph[1].vertex = 2;
	graph[2].vertex = 3;
	graph[3].vertex = 4;

	graph[0].next = new Node{ 2, new Node{4, NULL} };
	graph[1].next = new Node{ 1, new Node{3, NULL} };
	graph[2].next = new Node{ 2, NULL };
	graph[3].next = new Node{ 1, NULL };

	printList(graph);

	system("pause");
	return 0;
}

void printList(Node adjList[4]) {
	for (int i = 1; i <= 4; i++) {
		Node* next = adjList[i-1].next;
		while (next) {
			cout << "<" << i << "," << next->vertex << "> ";
			next = next->next;
		}
	}
	cout << endl;
}