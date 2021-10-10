/*John Winward
* CPSC 250
* 10/9/2021
* Hands-On Exercise 4 */
#include <iostream>

using namespace std;

//sorting algorithms
void insertionSort(int a[], int n);
void mergeSort(int a[], int first, int last);
void merge(int arr[], int first, int mid, int last);

int main()
{
	//create array
	int n = 10;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = (double)(n - i);

	}

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;

	system("pause");
	return 0;
}

//insertion sort
void insertionSort(int a[], int n)
{
	for (int unsorted = 0; unsorted <n; unsorted++)
	{
		int nextItem = a[unsorted];
		int loc = unsorted;
		while(loc > 0 && (a[loc - 1] > nextItem))
		{
			a[loc] = a[loc - 1];
			loc--;
		}
		a[loc] = nextItem;
	}
}

//merge sort
void mergeSort(int a[], int first, int last)
{
	if (first < last)
	{
		//get midpoint
		int mid = (first + last) / 2;

		//sort first half
		mergeSort(a, first, mid);
		
		//sort second half
		mergeSort(a, mid + 1, last);

		//merge sorted halves
		merge(a, first, mid, last);
	}
}

//merge function for merge sort
void merge(int a[], int first, int mid, int last)
{
	int size = last - first + 1;
	int* temp = new int[size];
	int l = first, r = mid + 1, index = 0;
	
	while (index < size)
	{
		if (a[l] < a[r])
		{
			temp[index] = a[l];
			index++;
			l++;
		}
		else
		{
			temp[index] = a[r];
			index++;
			r++;
		}
	}

	for (int i = 0; i < size; i++)
		cout << temp[i] << " ";
	cout << endl;

	index = 0;
	for (int i = first; i <= last; i++)
	{
		a[i] = temp[index];
		index++;
	}

}