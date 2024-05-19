#include <iostream>
#include <thread>
#include <vector>
#include <numeric>
#include <future>

double accum(double* beg, double* end, double init)
{
	return std::accumulate(beg, end, init);
}

// they enable a transfer of value and get result between two tasks 
// no lock needed
int main()
{
	std::vector<double>v{ 1, 2, 3, 4, 5 };

	using Task_Type = double(double*, double*, double);

	std::packaged_task<Task_Type>pt0{ accum };
	std::packaged_task<Task_Type>pt1{ accum };

	std::future<double>f0(pt0.get_future());
	std::future<double>f1(pt1.get_future());

	double* first = &v[0];
	std::thread t1{ std::move(pt0), first, first + v.size() / 2, 0 };
	std::thread t2{ std::move(pt1), first + v.size() / 2, first + v.size(), 0 };

	double sum = f0.get() + f1.get();
	std::cout << sum << std::endl;
}