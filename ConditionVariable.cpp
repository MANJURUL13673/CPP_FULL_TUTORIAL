#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

using namespace std;

struct Message 
{
	int x;
	int y;
};

queue<Message> mqueue;
condition_variable mcond;
mutex mmutex;

void consumer()
{
	while (true)
	{
		unique_lock <mutex> lck{ mmutex };
		mcond.wait(lck);	//wait untill the message is ready
		auto m = mqueue.front();
		mqueue.pop();
		std::cout << "consumed" << std::endl;
		lck.unlock();
	}
}

void producer()
{
	while (true)
	{
		Message m;
		m.x = 1.0;
		m.y = 2.0;
		this_thread::sleep_for(chrono::seconds(2));
		unique_lock<mutex> lck2(mmutex);
		mqueue.push(m);
		std::cout << "produced" << std::endl;
		mcond.notify_one();	//notify that the message is produced
	}
}

int main()
{
	thread t1{ consumer };
	thread t2{ producer };
	t1.join();
	t2.join();
	return 0;
}