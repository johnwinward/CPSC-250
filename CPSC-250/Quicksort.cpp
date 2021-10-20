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
void partition(int a[], int first, int last);
void quickSortMod(int a[], int first, int last);
void partitionMod(int a[], int first, int last);
void buildArray(int a[], int n);

int main()
{
	//

	system("pause");
	return 0;
}

void buildArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - i;
	}
}