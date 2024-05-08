#include <iostream>
#include <vector>
#include <thread>

void f(const std::vector<double>& v, double* res) {
	double sum = 0;
	for (int i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}
	*res = sum;
	std::cout << "Function Thread" << std::endl;
}

struct F {
	std::vector<double>& v;
	F(std::vector<double>& vv, double* res) : v{ vv } {
		double sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}
		*res = sum;
		std::cout << "Constructor Thread" << std::endl;
	}
	void operator()() {
		std::cout << "Thread start" << std::endl;
	};
};


int main()
{
	std::vector<double>some_vec{ 1, 2, 3, 4, 5 };
	std::vector<double>vec2{ 10, 11, 12, 13 };
	double sum1, sum2;
	std::thread t1{ f, some_vec, &sum1 };
	std::thread t2{ F(vec2, &sum2) };

	t1.join();
	t2.join();

	std::cout << sum1 << std::endl;
	std::cout << sum2 << std::endl;
	return 0;
}