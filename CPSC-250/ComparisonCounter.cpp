/*John Winward
* CPSC 250
* 10/9/2021
* Hands-On Exercise 4 */
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

//sorting algorithms
int insertionSort(int a[], int n);
int mergeSort(int a[], int first, int last);
int merge(int arr[], int first, int mid, int last);
void printArray(int a[], int n);
void buildArray(int a[], int n);

//Constants
int WIDTH = 25;

int main()
{

	//declarations
	int a2[2], a4[4], a8[8], a16[16];
	int a32[32], a64[64], a128[128], a256[256];
	int a512[512], a1024[1024], a2048[2048];
	int a8192[8192], a16384[16384];

	clock_t start;
	clock_t finish;

	int insertionComparisons;
	int mergeComparisons;
	int insertionTime;
	int mergeTime;

	//initialize arrays
	buildArray(a2, 2);
	buildArray(a4, 4);
	buildArray(a8, 8);
	buildArray(a16, 16);
	buildArray(a32, 32);
	buildArray(a64, 64);
	buildArray(a128, 128);
	buildArray(a256, 256);
	buildArray(a512, 512);
	buildArray(a1024, 1024);
	buildArray(a2048, 2048);
	buildArray(a8192, 8192);
	buildArray(a16384, 16384);

	//print heading
	cout << left << setw(WIDTH) << "n" << setw(WIDTH) << "Insertion Comparisons" << setw(WIDTH) << "Insertion Time"
		<< setw(WIDTH) << "Merge Comparisons" << setw(WIDTH) << "Merge Time" << endl;

	//begin testing (n = 2)
	start = clock();
	insertionComparisons = insertionSort(a2, 2);
	finish = clock();

	insertionTime = finish - start;

	buildArray(a2, 2);

	start = clock();
	mergeComparisons = mergeSort(a2, 0, 1);
	finish = clock();

	mergeTime = finish - start;

	cout << setw(WIDTH) << "2" << setw(WIDTH) << insertionComparisons << setw(WIDTH) << insertionTime
		<< setw(WIDTH) << mergeComparisons << setw(WIDTH) << mergeTime << endl;

	//n = 4
	start = clock();
	insertionComparisons = insertionSort(a4, 4);
	finish = clock();

	insertionTime = finish - start;

	buildArray(a4, 4);

	start = clock();
	mergeComparisons = mergeSort(a4, 0, 3);
	finish = clock();

	mergeTime = finish - start;

	cout << setw(WIDTH) << "4" << setw(WIDTH) << insertionComparisons << setw(WIDTH) << insertionTime
		<< setw(WIDTH) << mergeComparisons << setw(WIDTH) << mergeTime << endl;

	system("pause");
	return 0;
}

//insertion sort
int insertionSort(int a[], int n)
{
	int comparisons = 0;
	for (int unsorted = 0; unsorted <n; unsorted++)
	{
		int nextItem = a[unsorted];
		int loc = unsorted;
		while(loc > 0 && (a[loc - 1] > nextItem))
		{
			comparisons++;
			a[loc] = a[loc - 1];
			loc--;
		}
		a[loc] = nextItem;
	}

	return comparisons;
}

//merge sort
int mergeSort(int a[], int first, int last)
{
	int comparisons = 0;
	if (first < last)
	{
		//get midpoint
		int mid = (first + last) / 2;

		//sort first half
		mergeSort(a, first, mid);
		
		//sort second half
		mergeSort(a, mid + 1, last);

		//merge sorted halves
		comparisons = merge(a, first, mid, last);
	}
	return comparisons;
}

//merge function for merge sort
int merge(int a[], int first, int mid, int last)
{
	int comparisons = 0;
	int size = last - first + 1;
	int* temp = new int[size];
	int l = first, r = mid + 1, index = 0;
	
	while (l <= mid && r <= last)
	{
		if (a[l] <= a[r])
		{
			comparisons++;
			temp[index] = a[l];
			index++;
			l++;
		}
		else if(a[r] < a[l])
		{
			comparisons++;
			temp[index] = a[r];
			index++;
			r++;
		}
	}

	while (index < size)
	{
		if (l <= mid)
		{
			temp[index] = a[l];
			index++;
			l++;
		}
		else if (r <= last)
		{
			temp[index] = a[r];
			index++;
			r++;
		}
	}

	index = 0;
	for (int i = first; i <= last; i++)
	{
		a[i] = temp[index];
		index++;
	}

	return comparisons;

}

void printArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void buildArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = (double)(n - i);

	}
}