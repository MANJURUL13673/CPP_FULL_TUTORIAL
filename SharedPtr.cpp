#include <iostream>
#include <memory>

int main()
{
	std::shared_ptr<int>a = std::make_shared<int>(42);
	std::cout << *a << std::endl;

	std::shared_ptr<int>b;
	b = a;	//unique_ptr does not shared copy but shared_ptr supports shared_ptr
	std::cout << *b << std::endl;

	// all other things are same as unique_ptr
}