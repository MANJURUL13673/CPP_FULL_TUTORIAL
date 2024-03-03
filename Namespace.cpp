#include <iostream>

namespace My_Code {
	void main();
}

void My_Code::main() {
	std::cout << "Main does not conflict due to namespace" << std::endl;
}

// though their is another main, but for different namespace it works
int main()
{
	My_Code::main();
	std::cout << "original main" << std::endl;
}