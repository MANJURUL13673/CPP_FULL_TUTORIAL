#include <iostream>

int main()
{
	int v[] = { 0, 1, 2, 3, 4, 5 };
	for (int x : v)
	{
		std::cout << x << " ";
	}
	std::cout << std::endl;

	for (int& x : v)
	{
		std::cout << x << " ";
		x++;	//as i capture values with referrence so  this change affect in the array also
	}
	std::cout << std::endl;

	for (int x : v)
	{
		std::cout << x << " ";
	}
}

