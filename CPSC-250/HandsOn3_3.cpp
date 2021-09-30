/*
	John Winward
	9/30/2021
	CPSC 250
	Hands-On Exercise #3
*/

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int loopA(int n); //n is input size
int loopB(int n); //n is input size
int loopC(int n); //n is input size
void printResult(unsigned long long int s, double t);

int COLUMN_WIDTH = 25;

int main()
{
	clock_t start;	//clock_t used to get execution time data
	clock_t finish;
	unsigned long long int resultA;
	unsigned long long int resultB;
	unsigned long long int resultC;
	double timeA;
	double timeB;
	double timeC;
	int n;

	//Setup table
	cout << setw(COLUMN_WIDTH) << left << "n Value" << setw(COLUMN_WIDTH) << "Result of A" <<
		setw(COLUMN_WIDTH) << "Time of A (s)" << setw(COLUMN_WIDTH) << "Result of B" << setw(COLUMN_WIDTH) << "Time of B (s)" << 
		setw(COLUMN_WIDTH) << "Result of C" << setw(COLUMN_WIDTH) << "Time of C (s)" << endl;

	//Test both loops with input size of 3, print row of results
	n = 3;
	cout << setw(COLUMN_WIDTH) << n;

	start = clock();
	resultA = loopA(n);
	finish = clock();
	timeA = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultA, timeA);

	start = clock();
	resultB = loopB(n);
	finish = clock();
	timeB = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultB, timeB);

	start = clock();
	resultC = loopC(n);
	finish = clock();
	timeC = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultC, timeC);
	cout << endl;

	//Test for n = 10
	n = 10;
	cout << setw(COLUMN_WIDTH) << n;

	start = clock();
	resultA = loopA(n);
	finish = clock();
	timeA = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultA, timeA);

	start = clock();
	resultB = loopB(n);
	finish = clock();
	timeB = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultB, timeB);

	start = clock();
	resultC = loopC(n);
	finish = clock();
	timeC = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultC, timeC);
	cout << endl;

	//n = 1000
	n = 1000;
	cout << setw(COLUMN_WIDTH) << n;

	start = clock();
	resultA = loopA(n);
	finish = clock();
	timeA = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultA, timeA);

	start = clock();
	resultB = loopB(n);
	finish = clock();
	timeB = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultB, timeB);

	start = clock();
	resultC = loopC(n);
	finish = clock();
	timeC = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultC, timeC);
	cout << endl;

	//n = 100000
	n = 100000;
	cout << setw(COLUMN_WIDTH) << n;

	start = clock();
	resultA = loopA(n);
	finish = clock();
	timeA = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultA, timeA);

	start = clock();
	resultB = loopB(n);
	finish = clock();
	timeB = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultB, timeB);

	start = clock();
	resultC = loopC(n);
	finish = clock();
	timeC = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultC, timeC);
	cout << endl;

	//n = 1000000
	n = 1000000;
	cout << setw(COLUMN_WIDTH) << n;

	start = clock();
	resultA = loopA(n);
	finish = clock();
	timeA = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultA, timeA);

	start = clock();
	resultB = loopB(n);
	finish = clock();
	timeB = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultB, timeB);

	start = clock();
	resultC = loopC(n);
	finish = clock();
	timeC = static_cast<double>(finish - start) / CLOCKS_PER_SEC;

	printResult(resultC, timeC);
	cout << endl;

	system("pause");
	return 0;
}

int loopA(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum = sum + 1;
	return sum;
}

int loopB(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			sum = sum + i;
	return sum;
}

int loopC(int n)
{
	int sum = n * (n + 1) / 2;
	return sum;
}

void printResult(unsigned long long int s, double t)
{
	cout << setw(COLUMN_WIDTH) << s <<setw(COLUMN_WIDTH) << t;
}