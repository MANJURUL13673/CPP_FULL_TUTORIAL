#include <iostream>
#include <vector>
#include <numeric>
#include <future>

using namespace std;

double accum(double* beg, double* end, double init)
{
	return std::accumulate(beg, end, init);
}

int main()
{
	std::vector<double>v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i + 1);
	}

	auto v0 = &v[0];
	auto sz = v.size();

	// run task asynchronously
	auto f0 = std::async(accum, v0, v0 + sz / 4, 0.0);
	auto f1 = std::async(accum, v0 + sz / 4, v0 + sz / 2, 0.0);
	auto f2 = std::async(accum, v0 + sz / 2, v0 + sz * 3 / 4, 0.0);
	auto f3 = std::async(accum, v0 + sz * 3 / 4, v0 + sz, 0.0);

	// call those function for result asynchronously
	std::cout << f0.get() + f1.get() + f2.get() + f3.get() << std::endl;
	return 0;
}