#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

int number = 0;	//shared data
mutex mtx;


void f()
{
	mtx.lock();
	for (int i = 1; i <= 10000; i++)
	{
		number++;
	}
	mtx.unlock();
	//cout << sum << endl;
}

int main()
{
	thread t1{ f };
	thread t2{ f };
	t1.join();
	t2.join();

	cout << number << endl;

	return 0;
}