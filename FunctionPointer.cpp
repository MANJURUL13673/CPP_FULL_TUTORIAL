// operator_overloading.cpp
#include <iostream>
using namespace std;

int sum(int a, int b)
{
	return a + b;
}

int subtract(int a, int b)
{
	return a - b;
}

// pass function pointer
void anotherFunction(int (*passFunc) (int, int))
{
	std::cout << passFunc(10, 15) << std::endl;
}

int main()
{
	//basic of function pointer 
	int (*funcptr)(int, int);
	funcptr = sum;
	std::cout << funcptr(5, 6) << std::endl;
	
	// pass function pointer to another function
	anotherFunction(sum);
	
	// function pointer array
	int(*funcarr[2])(int, int) = { sum, subtract };
	std::cout << funcarr[0](4, 7) << " " << funcarr[1](11, 12) << std::endl;

	return 0;
}