#pragma once
using namespace std;

int const CAPACITY = 25;

class PriorityQueue
{
public:
	PriorityQueue();
	void insert(int n);
	int minimum();
	int extract_min();
	int parent(int i);
	int leftChild(int i);
	int rightChild(int i);
	void heapify(int i);
	void printQueue();

private:
	int heap_size;
	int a[CAPACITY];
};

PriorityQueue::PriorityQueue()
{
	heap_size = 0;
}