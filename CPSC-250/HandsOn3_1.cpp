/*
	John Winward
	9/24/2021
	CPSC 250
	Hands-On Exercise #3
*/

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int loopA(int n); //n is input size
int loopB(int n); //n is input size
void printRow(int n, unsigned long long int sA, unsigned long long int sB, double tA, double tB);

int COLUMN_WIDTH = 25;

int main()
{
	clock_t start;	//clock_t used to get execution time data
	clock_t finish;
	unsigned long long int resultA;
	unsigned long long int resultB;
	double timeA;
	double timeB;
	int n;

	//Setup table output
	cout << setw(COLUMN_WIDTH) << left << "n Value" << setw(COLUMN_WIDTH) << "Result of A" << 
		setw(COLUMN_WIDTH) << "Result of B" << setw(COLUMN_WIDTH) << "Time of A (s)" << setw(COLUMN_WIDTH) << "Time of B (s)" << endl;

	//Test both loops with input size of 3, print row of results
	n = 3;

	start = clock();
	resultA = loopA(n);
	finish = clock();
	timeA = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	resultB = loopB(n);
	finish = clock();
	timeB = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printRow(n, resultA, resultB, timeA, timeB);

	//Repeat for n = 10
	n = 10;

	start = clock();
	resultA = loopA(n);
	finish = clock();
	timeA = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	start = clock();
	resultB = loopB(n);
	finish = clock();
	timeB = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printRow(n, resultA, resultB, timeA, timeB);

	system("pause");
	return 0;
}

int loopA(int n)
{
	int sum = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= 10000; j++)
			sum = sum + j;
	return sum;
}

int loopB(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			sum = sum + j;
	return sum;
}

void printRow(int n, unsigned long long int sA, unsigned long long int sB, double tA, double tB)
{
	cout << setw(COLUMN_WIDTH) << n << setw(COLUMN_WIDTH) << sA << setw(COLUMN_WIDTH) << sB << 
		setw(COLUMN_WIDTH) << tA << setw(COLUMN_WIDTH) << tB << endl;
}