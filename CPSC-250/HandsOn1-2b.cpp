#include <iostream>
#include <math.h>

using namespace std;

void digitStack(unsigned int n);

int main()
{
	digitStack(1234050);

	return 0;
}

void digitStack(unsigned int n)
{
	if (n > 0)
	{
		digitStack(n / 10);
		cout << n % 10 << endl;
	}
}