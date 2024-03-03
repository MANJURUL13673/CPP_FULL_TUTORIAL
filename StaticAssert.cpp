#include <iostream>

class Vector {
private:
	double* elem;
	int siz;

public:
	Vector(int s) {
		if (s < 0)
		{
			throw std::length_error{ "negative size" };
		}
		elem = new double[s];
		siz = s;
	}	//here initialize the private elements outside of the bracket
	double& operator[](int i) 
	{
		if (i < 0 || size() <= i)
		{
			throw std::out_of_range{ "Vector::operator[]" };
		}
		return elem[i]; 
	}
	int size() { return siz; }
};

//exception finds error in runtime
//static assert finds error in compile time


int main()
{
	try
	{
		Vector v(-6);
	}
	catch (std::length_error)
	{
		std::cout << "negative error" << std::endl;
	}

	static_assert(2 > 3, "error generate");

	/*try {
		v[v.size()] = 7;
	}
	catch (std::out_of_range) {
		std::cout << "got exception" << std::endl;
	}*/
}