#include <iostream>

class Vector {
private:
	double* elem;
	size_t siz;

public:
	Vector(size_t s) : elem{ new double[s] }, siz{ s } { }	//here initialize the private elements outside of the bracket
	Vector(std::initializer_list<double>lst) : elem{ new double[lst.size()] }, siz{lst.size()} {
		std::copy(lst.begin(), lst.end(), elem);
	}
	~Vector() { delete[] elem; }						//delete allocated memory using destructor
	double& operator[](int i) { return elem[i]; }
	size_t size() { return siz; }
};
int main()
{
	Vector v = {1, 2, 3, 4, 5};

	int sum = 0;
	for (size_t i = 0; i < v.size(); i++)
	{
		sum += v[i];
	}

	std::cout << sum << std::endl;

}

