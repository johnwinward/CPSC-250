/*
	John Winward
	CPSC 250
	jwinward1@live.esu.edu
	10/24/2021
	Programming Assignment 2: Algorithm Analysis (Quicksort)
*/
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void quickSort(int a[], int first, int last, unsigned long long int& comparisons);
int partition(int a[], int first, int last, unsigned long long int& comparisons);
void sortFirstMiddleLast(int a[], int first, int mid, int last, unsigned long long int& comparisons);
void quickSortMod(int a[], int first, int last, unsigned long long int& comparisons);
int partitionMod(int a[], int first, int last, unsigned long long int& comparisons);
void buildArray(int a[], int n);
void printArray(int a[], int n);

//Constants
int WIDTH = 25;

int main()
{

	int a[16384];

	clock_t start;
	clock_t finish;

	unsigned long long int quickSortComparisons;
	unsigned long long int quickSortModComparisons;
	int quickSortTime;
	int quickSortModTime;

	//print heading
	cout << left << setw(WIDTH) << "n" << setw(WIDTH) << "Quicksort Comparisons" << setw(WIDTH) << "Quicksort Time"
		<< setw(WIDTH) << "Modified QS Comparisons" << setw(WIDTH) << "Modified QS Time" << endl;

	//begin testing and printing results
	for (int i = 2; i <= 16384; i *= 2)
	{
		buildArray(a, i);
		quickSortComparisons = 0;
		start = clock();
		quickSort(a, 0, i - 1, quickSortComparisons);
		finish = clock();
		quickSortTime = finish - start;

		buildArray(a, i);
		quickSortModComparisons = 0;
		start = clock();
		quickSortMod(a, 0, i - 1, quickSortModComparisons);
		finish = clock();
		quickSortModTime = finish - start;

		cout << setw(WIDTH) << i << setw(WIDTH) << quickSortComparisons << setw(WIDTH) << quickSortTime
			<< setw(WIDTH) << quickSortModComparisons << setw(WIDTH) << quickSortModTime << endl;
	}

	system("pause");
	return 0;
}

void quickSort(int a[], int first, int last, unsigned long long int& comparisons)
{
	if (first < last)
	{
		//partition array and find pivot
		int pivot = partition(a, first, last, comparisons);

		//quickSort array before pivot
		quickSort(a, first, pivot - 1, comparisons);

		//quickSort array after pivot
		quickSort(a, pivot + 1, last, comparisons);
	}
}

int partition(int a[], int first, int last, unsigned long long int& comparisons)
{
	//find middle index
	int mid = first + (last - first) / 2;

	//find and reposition pivot to middle
	sortFirstMiddleLast(a, first, mid, last, comparisons);

	if (last - first > 2)
	{
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
			comparisons++;
			while (a[left] < pValue)
			{
				comparisons++;
				left++;
			}

			//find right value out of place
			comparisons++;
			while (a[right] > pValue)
			{
				comparisons++;
				right--;
			}

			//swap left and right values if left is still < right
			comparisons++;
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

	return mid;
}

void sortFirstMiddleLast(int a[], int first, int mid, int last, unsigned long long int& comparisons)
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
	comparisons += 3;
}

void quickSortMod(int a[], int first, int last, unsigned long long int& comparisons)
{
	if (first < last)
	{
		//partition array and find pivot
		int pivot = partitionMod(a, first, last, comparisons);

		//quickSort array before pivot
		quickSortMod(a, first, pivot - 1, comparisons);

		//quickSort array after pivot
		quickSortMod(a, pivot + 1, last, comparisons);
	}
}

int partitionMod(int a[], int first, int last, unsigned long long int& comparisons)
{
	int temp; //for swapping

	//swap last value with first value
	temp = a[first];
	a[first] = a[last];
	a[last] = temp;

	//store pivot index and pivot value
	int pIndex = first;
	int pValue = a[pIndex];

	//create regions for < pivot and > pivot
	int left = first + 1;
	int right = last;
	bool done = false;

	while (!done)
	{
		//find left value out of place
		comparisons++;
		while (left <= last && a[left] < pValue)
		{
			comparisons++;
			left++;
		}

		//find right value out of place
		comparisons++;
		while (a[right] > pValue)
		{
			comparisons++;
			right--;
		}

		//swap left and right values if left is still < right
		comparisons++;
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
	a[pIndex] = a[right];
	a[right] = temp;

	//set and return new pivot index
	pIndex = right;
	return pIndex;
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