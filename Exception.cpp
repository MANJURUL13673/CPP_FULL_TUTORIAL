#include <iostream>

class Vector {
private:
	double* elem;
	int siz;

public:
	Vector(int s) : elem{ new double[s] }, siz{ s } { }	//here initialize the private elements outside of the bracket
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

// Remember for interview
// if you declare object inside try and throw exception from the destructor it will show runtime error


int main()
{
	Vector v(6);
	try {
		v[v.size()] = 7;
	}
	catch (std::out_of_range) {
		std::cout << "got exception" << std::endl;
	}
}