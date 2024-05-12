#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <exception>

using namespace std;

struct Message 
{
	int x;
	int y;
};

void f(promise<Message>&& px)
{
	try
	{
		Message msg;
		msg.x = 10;
		msg.y = 15;
		this_thread::sleep_for(chrono::seconds(10));
		px.set_value(msg);
	}
	catch (exception e) 
	{
		px.set_exception(current_exception());
	}
}

void g(future<Message>&& fx)
{
	try {
		Message msg = fx.get();
		cout << msg.x << " " << msg.y << std::endl;
	}
	catch (exception e)
	{
		//handle error
	}
}

int main()
{
	promise<Message> prms;
	future<Message>frms = prms.get_future();

	thread t1{ f, move(prms) };
	thread t2{ g, move(frms) };

	t1.join();
	t2.join();
	return 0;
}