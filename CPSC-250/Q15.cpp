#include <iostream>

void recurse(int& x, int y);

int main()
{
	int x = 5;
	int y = 3;
	recurse(x, y);
	return 0;
}

void recurse(int& x, int y)
{
	if (y > 0)
	{
		x++;
		y--;
		std::cout << x << " " << y << std::endl;
		recurse(x, y);
		std::cout << x << " " << y << std::endl;
	}
}