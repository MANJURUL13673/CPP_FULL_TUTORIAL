#include <iostream>
#include <memory>

// a pointer that is destroyed automatically
class Shape
{
public:
	void Print() {
		std::cout << "Method call" << std::endl;
	}
};

int main()
{
	// operations like a normal pointer
	std::unique_ptr<int>a(new int(42));
	std::cout << *a << std::endl;
	(*a)++;
	std::cout << *a << std::endl;

	// operation with array elements 
	std::unique_ptr<int[]>arr{new int[50]};
	
	for (int i = 0; i < 50; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < 50; i++) {
		std::cout << arr[i] << std::endl;
	}

	// operations with multidimensional array
	int rows = 3;
	int cols = 2;
	std::unique_ptr<std::unique_ptr<int[]>[]> arr2D(new std::unique_ptr<int[]>[rows]);
	for (int i = 0; i < rows; i++) {
		arr2D[i].reset(new int[cols]);
	}

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr2D[i][j] = i;
		}
	}
	// move semantics
	//std::unique_ptr<int>copyPtr = a;	// not work
	std::unique_ptr<int>copyPtr = std::move(a);	// support move
	std::cout << *copyPtr << std::endl;

	// handling class
	std::unique_ptr<Shape>classPtr(new Shape());
	classPtr->Print();

	// make_unique
	std::unique_ptr<int[]>test = std::make_unique<int[]>(5);	//it is also a way to create dynamically


	return 0;
}