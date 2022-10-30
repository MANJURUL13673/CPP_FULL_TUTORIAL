//
// Array Class
// Arrays are fixed-size sequence containers: they hold a specific number of elements ordered in a strict linear sequence
//

//
// Initialization - {}
// Copy Initialization - = 
// Traversing Elements - auto
// Assign values - at
// get and set last and first value - front(), back()
// begin and end pointer of array object- begin(), end()
// constant begin and end pointer of array object- cbegin(), cend()
// reverse order of begin and end pointer of array object- rbegin(), rend()
// constant reverse order of begin and end pointer of array object- crbegin(), crend()
// return the pointer of the first element of array object - data()
// check size is empty or not - empty()
// fill the array with specefic value - fill()
// size of the array - size(), max_size()
// traversing element - []
// swap array elements - swap()
// get a position elements - get()
// reletational operator (check lexicographically) - ==, !=, <, >, <=, >=
// 

#include <iostream>
#include <array>
#include <tuple>

std::array<int, 3> global;		//zero initialized

int main()
{
	// initalize
	std::array<int, 3> first;	//uninitialized
	std::array<int, 3> second = { 10, 20 };		//initialized as: {10, 20, 0}
	std::array<int, 3> third = { 1, 2, 3 };		//initialized as: {1, 2, 3}

	// copy initialization
	std::array<int, 3> fourth = third;	//copy:		{1, 2, 3}

	// traversing elements
	for (auto x : fourth) std::cout << " " << x;
	std::cout << "\n\n";

	// assign values
	std::array<int, 10>myArr;
	for (int i = 0; i < 10; i++) myArr.at(i) = i + 1;
	for (int i = 0; i < 10; i++) std::cout << " " << myArr.at(i);
	std::cout << "\n\n";

	// get and set first and last values
	std::cout << myArr.front() << std::endl;
	std::cout << myArr.back() << std::endl;
	myArr.back() = 50;
	for (int& x : myArr) std::cout << " " << x;
	std::cout << "\n\n";

	// using begin and end pointer
	for (auto it = myArr.begin(); it != myArr.end(); it++) std::cout << " " << *it;
	std::cout << "\n\n";

	// using cbegin and cend const pointer. 
	// value of const pointer can not change
	for (auto it = myArr.cbegin(); it != myArr.cend(); it++)
	{
		//*it = *it + 5; //wrong statement -> const pointer
		std::cout << " " << *it;
	}
	std::cout << "\n\n";

	// using rebgin and rend pointer
	// reverse iteration
	for (auto it = myArr.rbegin(); it != myArr.rend(); it++) std::cout << " " << *it;
	std::cout << "\n\n";

	// using crbegin and crbegin const pointer in reverse iteration
	for (auto it = myArr.crbegin(); it != myArr.crend(); it++)
	{
		//*it = *it + 5; //wrong statement -> const pointer
		std::cout << " " << *it;
	}
	std::cout << "\n\n";

	// using data
	// returns pointer to the first element in the array object
	const char* cstr = "Test string";
	std::array<char, 12> charArr;

	std::memcpy(charArr.data(), cstr, 12);

	std::cout << charArr.data() << "\n\n";

	// empty() return bool true if size is 0
	std::array<int, 0> emptyArr;
	std::array<int, 5> nonEmptyArr;
	std::cout << emptyArr.empty() << "\n";
	std::cout << nonEmptyArr.empty() << "\n";
	std::cout << "\n\n";

	// fill the array with a specefic value
	myArr.fill(5);
	for (int& x : myArr) std::cout << " " << x;
	std::cout << "\n\n";

	// get array size and max_size
	// size and max_size are similar for Array Class
	std::cout << myArr.size() << "\n";
	std::cout << myArr.max_size() << "\n";
	std::cout << "\n\n";

	// access element using operator []
	for (int i = 0; i < myArr.size(); i++) std::cout << " " << myArr[i];
	std::cout << "\n\n";

	// swap two array it's element
	// array must be have same time and same size
	std::array<int, 5>firstArr = { 1, 2, 3, 4, 5 };
	std::array<int, 5>secondArr = { 6, 7, 8, 9, 10 };
	firstArr.swap(secondArr);
	for (int& x : firstArr) std::cout << " " << x;
	std::cout << "\n";
	for (int& y : secondArr) std::cout << " " << y;
	std::cout << "\n";
	std::cout << "\n\n";

	// get the i'th element of array
	std::array<int, 3>Arr = { 10, 20, 30 };
	std::tuple<int, int, int>mytuple (10, 20, 30);
	std::tuple_element<0, decltype(Arr)>::type myelement;

	myelement = std::get<2>(Arr);
	std::get<2>(Arr) = std::get<0>(Arr);
	std::get<0>(Arr) = myelement;

	std::cout << std::get<0>(Arr) << "\n";
	std::cout << std::get<0>(mytuple) << "\n";
	std::cout << "\n\n";

	// releational operator:: ==, !=, <, >, <=, >=
	std::array<int, 5> a = { 10, 20, 30, 40, 50 };
	std::array<int, 5> b = { 10, 20, 30, 40, 50 };
	std::array<int, 5> c = { 50, 40, 30, 20, 10 };

	// == Check Equal
	if (a == b) std::cout << "Equal" << "\n";
	// != Check Not Equal
	if (a != c)std::cout << "Not Equal" << "\n";
	// >, <, >=, <= Check Lexigraphically
	if (c >= a) std::cout << "Greater or equal" << "\n";
	if (a >= c) std::cout << "Less or equal" << "\n";
	return 0;
}
