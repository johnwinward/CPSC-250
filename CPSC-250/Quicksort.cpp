/*
	John Winward
	CPSC 250
	jwinward1@live.esu.edu
	10/18/2021
	Programming Assignment 2: Algorithm Analysis (Quicksort)
*/
#include <iostream>

using namespace std;

void quickSort(int a[], int first, int last);
int partition(int a[], int first, int last);
void sortFirstMiddleLast(int a[], int first, int mid, int last);
void quickSortMod(int a[], int first, int last);
void partitionMod(int a[], int first, int last);
void buildArray(int a[], int n);
void printArray(int a[], int n);

int main()
{
	//
	int a[10];
	buildArray(a, 10);
	printArray(a, 10);

	quickSort(a, 0, 9);
	cout << endl;
	printArray(a, 10);

	system("pause");
	return 0;
}

void quickSort(int a[], int first, int last)
{
	if (first < last)
	{
		//partition array and find pivot
		int pivot = partition(a, first, last);

		//quickSort array before pivot
		quickSort(a, first, pivot - 1);

		//quickSort array after pivot
		quickSort(a, pivot + 1, last);
	}
}

int partition(int a[], int first, int last)
{
	//find middle index
	int mid = first + (last - first) / 2;
	
	//find and reposition pivot to middle
	sortFirstMiddleLast(a, first, mid, last);

	//Swap pivot with index before last
	int temp = a[mid];
	a[mid] = a[last - 1];
	a[last - 1] = temp;

	//store pivot index and pivot value
	int pIndex = last - 1;
	int pValue = a[pIndex];


	//create regions for < pivot and > pivot
	int left = first + 1;
	int right = last - 2;
	bool done = false;

	while (!done)
	{
		//find left value out of place
		while (a[left] < pValue)
			left++;

		//find right value out of place
		while (a[right] > pValue)
			right--;

		//swap left and right values if left is still < right
		if (left < right)
		{
			//swap left value and right value
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;

			//continue region sort process
			left++;
			right--;
		}
		else
			done = true;
	}

	//place pivot between regions now that they are created
	temp = a[pIndex];
	a[pIndex] = a[left];
	a[left] = temp;

	//set and return new pivot index
	pIndex = left;
	return pIndex;
}

void sortFirstMiddleLast(int a[], int first, int mid, int last)
{
	int temp;
	//compare first and mid values, swap if out of order
	if (a[first] > a[mid])
	{
		temp = a[first];
		a[first] = a[mid];
		a[mid] = temp;
	}

	//compare mid and last values, swap if out of order
	if (a[mid] > a[last])
	{
		temp = a[mid];
		a[mid] = a[last];
		a[last] = temp;
	}

	//repeat first step
	if (a[first] > a[mid])
	{
		temp = a[first];
		a[first] = a[mid];
		a[mid] = temp;
	}
}

void buildArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - i;
	}
}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}