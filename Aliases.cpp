#include <iostream>
#include <map>
#include <string>

template<typename Val>
using StringMap = std::map<std::string, Val>;

int main()
{
	// works like map and key is string and value is int
	StringMap<int>s;
	s["hello"] = 1;

	// here some but key is string and value is double
	StringMap<double>v;
	v["hi"] = 2.0;

	std::cout << s["hello"] << " " << v["hi"] << std::endl;
	return 0;
}