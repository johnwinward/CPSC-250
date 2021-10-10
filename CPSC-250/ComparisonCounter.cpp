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

	//n = 8
	start = clock();
	insertionComparisons = insertionSort(a8, 8);
	finish = clock();

	insertionTime = finish - start;

	buildArray(a8, 8);

	start = clock();
	mergeComparisons = mergeSort(a8, 0, 7);
	finish = clock();

	mergeTime = finish - start;

	cout << setw(WIDTH) << "8" << setw(WIDTH) << insertionComparisons << setw(WIDTH) << insertionTime
		<< setw(WIDTH) << mergeComparisons << setw(WIDTH) << mergeTime << endl;

	//n = 16
	start = clock();
	insertionComparisons = insertionSort(a16, 16);
	finish = clock();

	insertionTime = finish - start;

	buildArray(a16, 16);

	start = clock();
	mergeComparisons = mergeSort(a16, 0, 15);
	finish = clock();

	mergeTime = finish - start;

	cout << setw(WIDTH) << "16" << setw(WIDTH) << insertionComparisons << setw(WIDTH) << insertionTime
		<< setw(WIDTH) << mergeComparisons << setw(WIDTH) << mergeTime << endl;

	//n = 32
	start = clock();
	insertionComparisons = insertionSort(a32, 32);
	finish = clock();

	insertionTime = finish - start;

	buildArray(a32, 32);

	start = clock();
	mergeComparisons = mergeSort(a32, 0, 31);
	finish = clock();

	mergeTime = finish - start;

	cout << setw(WIDTH) << "32" << setw(WIDTH) << insertionComparisons << setw(WIDTH) << insertionTime
		<< setw(WIDTH) << mergeComparisons << setw(WIDTH) << mergeTime << endl;

	//n = 64
	start = clock();
	insertionComparisons = insertionSort(a64, 64);
	finish = clock();

	insertionTime = finish - start;

	buildArray(a64, 64);

	start = clock();
	mergeComparisons = mergeSort(a64, 0, 63);
	finish = clock();

	mergeTime = finish - start;

	cout << setw(WIDTH) << "64" << setw(WIDTH) << insertionComparisons << setw(WIDTH) << insertionTime
		<< setw(WIDTH) << mergeComparisons << setw(WIDTH) << mergeTime << endl;

	//n = 128
	start = clock();
	insertionComparisons = insertionSort(a128, 128);
	finish = clock();

	insertionTime = finish - start;

	buildArray(a128, 128);

	start = clock();
	mergeComparisons = mergeSort(a128, 0, 127);
	finish = clock();

	mergeTime = finish - start;

	cout << setw(WIDTH) << "128" << setw(WIDTH) << insertionComparisons << setw(WIDTH) << insertionTime
		<< setw(WIDTH) << mergeComparisons << setw(WIDTH) << mergeTime << endl;

	//n = 256
	start = clock();
	insertionComparisons = insertionSort(a256, 256);
	finish = clock();

	insertionTime = finish - start;

	buildArray(a256, 256);

	start = clock();
	mergeComparisons = mergeSort(a256, 0, 255);
	finish = clock();

	mergeTime = finish - start;

	cout << setw(WIDTH) << "256" << setw(WIDTH) << insertionComparisons << setw(WIDTH) << insertionTime
		<< setw(WIDTH) << mergeComparisons << setw(WIDTH) << mergeTime << endl;

	//n = 512
	start = clock();
	insertionComparisons = insertionSort(a512, 512);
	finish = clock();

	insertionTime = finish - start;

	buildArray(a512, 512);

	start = clock();
	mergeComparisons = mergeSort(a512, 0, 511);
	finish = clock();

	mergeTime = finish - start;

	cout << setw(WIDTH) << "512" << setw(WIDTH) << insertionComparisons << setw(WIDTH) << insertionTime
		<< setw(WIDTH) << mergeComparisons << setw(WIDTH) << mergeTime << endl;

	//n = 1024
	start = clock();
	insertionComparisons = insertionSort(a1024, 1024);
	finish = clock();

	insertionTime = finish - start;

	buildArray(a1024, 1024);

	start = clock();
	mergeComparisons = mergeSort(a1024, 0, 1023);
	finish = clock();

	mergeTime = finish - start;

	cout << setw(WIDTH) << "1024" << setw(WIDTH) << insertionComparisons << setw(WIDTH) << insertionTime
		<< setw(WIDTH) << mergeComparisons << setw(WIDTH) << mergeTime << endl;

	//n = 2048
	start = clock();
	insertionComparisons = insertionSort(a2048, 2048);
	finish = clock();

	insertionTime = finish - start;

	buildArray(a2048, 2048);

	start = clock();
	mergeComparisons = mergeSort(a2048, 0, 2047);
	finish = clock();

	mergeTime = finish - start;

	cout << setw(WIDTH) << "2048" << setw(WIDTH) << insertionComparisons << setw(WIDTH) << insertionTime
		<< setw(WIDTH) << mergeComparisons << setw(WIDTH) << mergeTime << endl;

	//n = 8192
	start = clock();
	insertionComparisons = insertionSort(a8192, 8192);
	finish = clock();

	insertionTime = finish - start;

	buildArray(a8192, 8192);

	start = clock();
	mergeComparisons = mergeSort(a8192, 0, 8191);
	finish = clock();

	mergeTime = finish - start;

	cout << setw(WIDTH) << "8192" << setw(WIDTH) << insertionComparisons << setw(WIDTH) << insertionTime
		<< setw(WIDTH) << mergeComparisons << setw(WIDTH) << mergeTime << endl;

	//n = 16384
	start = clock();
	insertionComparisons = insertionSort(a16384, 16384);
	finish = clock();

	insertionTime = finish - start;

	buildArray(a16384, 16384);

	start = clock();
	mergeComparisons = mergeSort(a16384, 0, 16383);
	finish = clock();

	mergeTime = finish - start;

	cout << setw(WIDTH) << "16384" << setw(WIDTH) << insertionComparisons << setw(WIDTH) << insertionTime
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
		comparisons += mergeSort(a, first, mid);
		
		//sort second half
		comparisons += mergeSort(a, mid + 1, last);

		//merge sorted halves
		comparisons += merge(a, first, mid, last);
	}
	return comparisons;
}

//merge function for merge sort
int merge(int a[], int first, int mid, int last)
{
	int comparisons = 0;

	//initialize temp array
	int size = last - first + 1;
	int* temp = new int[size];

	//left array, right array, and temp array index
	int l = first, r = mid + 1, index = 0;
	
	while (l <= mid && r <= last)
	{
		if (a[l] <= a[r]) //if left array value is less than right array value
		{
			//insert left array value into temp array
			comparisons++; //increment comparisons
			temp[index] = a[l];
			index++;
			l++;
		}
		else if(a[r] < a[l]) //if right array value is less than left array value
		{
			//insert left array value into temp array
			comparisons++; //increment comparisons
			temp[index] = a[r];
			index++;
			r++;
		}
	}

	//fill in remaining left or right array values
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

	//move temp array to original array
	index = 0;
	for (int i = first; i <= last; i++)
	{
		a[i] = temp[index];
		index++;
	}

	return comparisons;

}

void buildArray(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = (double)(n - i);

	}
}