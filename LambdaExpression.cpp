#include <iostream>
using namespace std;

int main()
{
	//normal lambda expression
	/*
		[capture](parameter) -> returntype {
			lambda body
		};
	*/

	//normal lambda
	auto greet = []() {
		std::cout << "Hello World" << std::endl;
	};

	//lambda function with parameter and return value
	auto add = [](int a, int b) {
		return a + b;
	};

	greet();
	int sum = add(5, 6);	//sum of two numbers
	std::cout << sum << std::endl;

	//lambda function with parameter and return type
	auto operation = [](int a, int b) -> double {
		return a / (b * 1.0);
	};

	double div = operation(6, 5);
	std::cout << div << std::endl;

	int num_main = 100;

	//lambda function with capture value. 
	//capture means out of function variable can accessible inside function
	auto my_lambda = [num_main]() {
		std::cout << num_main << std::endl;
	};

	my_lambda();

	//capture with referrence, so num_main value also change
	auto my_lambda1 = [&num_main]() {
		num_main = 900;
	};
	my_lambda1();
	std::cout << num_main << std::endl;

	//equal sign in capture that mean all the variable outside of function can be accessible
	auto my_lambda2 = [=]() {
		std::cout << num_main << std::endl;
	};
	my_lambda2();

	return 0;
}