#include <iostream> // needed to perform C++ I/O 
#include <string>
#include <time.h> //use clock_t start, stop;
using namespace std;
int rabbit(int n);
int IterativeRabbit(int n);
void writeBackward(string s);
void IterativewriteBackward(string s);
int binarySearch(const int anArray[], int first, int last, int target);
int IterativeBinarySearch(int array[], int size, int target);
const int SIZE = 40, SIZE2 = 100000;
int main()
{
	cout << "Part 1 **************\n";
	int res, array[SIZE2] = {};
	//for binary search tree
	for (int i = 0; i < SIZE2; i++)
	{
		array[i] = 2 * i + 1;
	}
	string s = "recursive function calls by itself ";
	clock_t start, stop;
	//rabbit functions
	start = clock();
	res = rabbit(SIZE);
	stop = clock();
	cout << "The return value of the rabbit function is " << res << endl;
	cout << "Running time for the function is " << static_cast<double>(stop - start)
		<< endl; //in miliseconds
	cout << endl;

	//Iterative rabbit functions
	start = clock();
	res = IterativeRabbit(SIZE);
	stop = clock();
	cout << "The return value of the iterative rabbit function is " << res << endl;
	cout << "Running time for the function is " << static_cast<double>(stop - start)
		<< endl; //in miliseconds

	//recursive writeBackward function
	cout << endl << "The output for the recursive writeBackward function is ";
	start = clock();
	writeBackward(s);
	stop = clock();
	cout << endl << "Running time for the function is " << static_cast<double>(stop - start) << endl;

	//iterative writeBackward function
	cout << endl << "The output for the iterative writeBackward function is ";
	start = clock();
	IterativewriteBackward(s);
	stop = clock();
	cout << endl << "Running time for the function is " << static_cast<double>(stop - start) << endl;

	//recursive binary search function
	cout << endl << "(Recursive) The index of the number in the array is ";
	start = clock();
	res = binarySearch(array, 0, SIZE2 - 1, 123123);
	stop = clock();
	cout << res;
	cout << endl << "Running time for the function is " << static_cast<double>(stop - start) << endl;

	//iterative binary search function
	cout << endl << "(Iterative) The index of the number in the array is ";
	start = clock();
	res = IterativeBinarySearch(array, SIZE2, 123123);
	stop = clock();
	cout << res;
	cout << endl << "Running time for the function is " << static_cast<double>(stop - start) << endl;


	system("pause");
	return 0;
}

int rabbit(int n)
{
	if (n < 2)
		return 1;
	else
	{
		return rabbit(n - 1) + rabbit(n - 2);
	}
}

int IterativeRabbit(int n)
{
	if (n < 2)
		return 1;
	else
	{
		int p1 = 1; //previous value 1
		int p2 = 1; //previous value 2
		int r = 0; //result
		for (int i = 2; i <= n; i++)
		{
			r = p1 + p2;
			p1 = p2;
			p2 = r;

		}
		return r;
	}
}

void writeBackward(string s)
{
	if (s.size() >= 1)
	{
		cout << s.substr(s.size() - 1, 1);
		writeBackward(s.substr(0, s.size() - 1));
	}
}

void IterativewriteBackward(string s)
{
	string new_s;
	for (int i = s.length(); i >= 0; i--)
	{
		new_s += s.substr(i, 1);
	}
	cout << new_s;
}

int binarySearch(const int anArray[], int first, int last, int target)
{
	int i = (last - first) / 2 + first;
	if (anArray[i] == target)
		return i;
	else if (last - first <= 1)
		return -1;
	else if (anArray[i] < target)
		return binarySearch(anArray, i, last, target);
	else if (anArray[i] > target)
		return binarySearch(anArray, first, i, target);
}

int IterativeBinarySearch(int array[], int size, int target)
{
	int first = 0, last = size - 1;
	int index = size / 2;
	while (last - first > 1)
	{
		index = (last - first) / 2 + first;
		if (array[index] < target)
			first = index;
		else if (array[index] > target)
			last = index;
		else if (array[index] == target)
			return index;
	}
	return -1;
}