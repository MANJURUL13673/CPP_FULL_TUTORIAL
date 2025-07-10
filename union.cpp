#include <iostream>
using namespace std;

int main()
{
	// union only takes one value
	union Data {
		int i;
		float f;
		char c;
	};
	Data data;
	// i will update with the last assigned value
	data.i = 42; // Assigning an integer value
	data.c = 'A'; // Assigning a character value

	std::cout << data.i << std::endl; // Output will be 'A' because union shares memory
	
	return 0;
}