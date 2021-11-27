/*
	John Winward
	CSPC 250
	jwinward1@live.esu.edu
	11/27/2021
	Programming Assignment 3
*/

#include "PriorityQueue.h"
#include <iostream>

int main() {
	
	PriorityQueue queue;
	queue.insert(59);
	queue.insert(41);
	queue.insert(25);
	queue.insert(12);
	queue.insert(91);

	cout << "59, 41, 25, 12, and 91 are inserted into queue (in that order)" << endl;
	cout << "Queue: ";
	queue.printQueue();
	cout << endl;

	cout << "Min is extracted" << endl;
	cout << "Queue: ";
	queue.extract_min();
	queue.printQueue();
	cout << endl;

	cout << "Min is extracted" << endl;
	cout << "Queue: ";
	queue.extract_min();
	queue.printQueue();
	cout << endl;

	cout << "Without extracting, the minimum value is " << queue.minimum() << endl;

	system("pause");
	return 0;
}

void PriorityQueue::insert(int n) {
	heap_size++;
	int i = heap_size - 1;
	while (i > 0 && a[parent(i)] > n) {
		a[i] = a[parent(i)];
		i = parent(i);
	}
	a[i] = n;
}

int PriorityQueue::minimum() {
	return a[0];
}

int PriorityQueue::extract_min() {
	int min = a[0];
	a[0] = a[heap_size - 1];
	heap_size--;
	heapify(0);
	return min;
}

int PriorityQueue::parent(int i) {
	return (i - 1) / 2;
}

int PriorityQueue::leftChild(int i) {
	return 2 * i + 1;
}

int PriorityQueue::rightChild(int i) {
	return 2 * i + 2;
}

void PriorityQueue::heapify(int i) {
	int smallest;
	int left = leftChild(i);
	int right = rightChild(i);
	if (left < heap_size && a[left] < a[i])
		smallest = left;
	else
		smallest = i;

	if (right < heap_size && a[right] < a[smallest])
		smallest = right;

	if (smallest != i) {
		int temp = a[i];
		a[i] = a[smallest];
		a[smallest] = temp;
		heapify(smallest);
	}
}

void PriorityQueue::printQueue() {
	for (int i = 0; i < heap_size; i++)
		cout << a[i] << " ";
	cout << endl;
}