#include <iostream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;

int main()
{
	auto t0 = high_resolution_clock::now();
	this_thread::sleep_for(seconds(2));
	auto t1 = high_resolution_clock::now();
	std::cout << duration_cast<milliseconds>(t1 - t0).count() << " nanoseconds passed\n";
	return 0;
}