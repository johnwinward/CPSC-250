/*
	John Winward
	11/2/2021
	CPSC 250
	Hands-On Exercise 7: Heaps and Priority Queues
*/

#include <iostream>

using namespace std;

int getParent(int index);
int getLeftChild(int index);
int getRightChild(int index);
void swap(int& item1, int& item2);
void heapify(int A[], int index, int size);
void build_heap(int A[], int size);
void printArray(int A[], int size);
void heapInsert(int A[], int& size, int item);

int main() {
	//Build array
	int A[20] = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
	int size = 10;

	//print original array
	cout << "Original Array: ";
	printArray(A, size);

	//create heap from array
	build_heap(A, size);

	//test output
	cout << "Heap Array: ";
	printArray(A, size);

	//test getLeftChild
	cout << "The left child of " << A[0] << " is " << A[getLeftChild(0)] << "." << endl;

	//test getRightChild
	cout << "The right child of " << A[0] << " is " << A[getRightChild(0)] << "." << endl;

	//insert 20 into heap
	heapInsert(A, size, 20);

	//test output
	cout << "Heap with 20 inserted: ";
	printArray(A, size);

	//insert 17
	heapInsert(A, size, 17);

	//test output
	cout << "Heap with 17 inserted: ";
	printArray(A, size);

	system("pause");
	return 0;
}

//Returns parent of a node in a heap
int getParent(int index) {
	return (index - 1) / 2;
}

//Returns the left child of a node in a heap
int getLeftChild(int index) {
	return 2 * index + 1;
}

//Returns the right child of a node in a heap
int getRightChild(int index) {
	return 2 * index + 2;
}

//Swaps two values
void swap(int& item1, int& item2) {
	int temp = item1;
	item1 = item2;
	item2 = temp;
}

//Organizes an array to follow heap rules
void heapify(int A[], int index, int size) {
	int left = getLeftChild(index);
	int right = getRightChild(index);
	int largest;

	if (left < size && A[left] > A[index])
		largest = left;
	else
		largest = index;

	if (right < size && A[right] > A[largest])
		largest = right;

	if (largest != index) {
		swap(A[index], A[largest]);
		heapify(A, largest, size);
	}
}

//changes an entire array into a array-based heap
void build_heap(int A[], int size) {
	for (int i = size / 2 - 1; i >= 0; i--)
		heapify(A, i, size);
}

//Outputs an array
void printArray(int A[], int size) {
	for (int i = 0; i < size; i++)
		cout << A[i] << " ";
	cout << endl;
}

void heapInsert(int A[], int& size, int item) {
	size++;
	int index = size - 1;
	while (index > 0 && A[getParent(index)] < item) {
		A[index] = A[getParent(index)];
		index = getParent(index);
	}
	A[index] = item;
}