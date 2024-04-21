#include <iostream>
#include <vector>
#include <thread>

void f() {
	std::cout << "Hello ";
}

struct F {
	void operator()() {
		std::cout << "Parralel World!\n";
	}
};

int main()
{
	std::thread t1{ f };
	std::thread t2{ F() };

	t1.join();
	t2.join();

	return 0;
}