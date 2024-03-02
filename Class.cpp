#include <iostream>

class Vector {
private:
	double* elem;
	int siz;

public:
	Vector(int s) : elem{ new double[s] }, siz{ s } { }	//here initialize the private elements outside of the bracket
	double& operator[](int i) { return elem[i]; }
	int size() { return siz; }
};
int main()
{
	Vector v(6);
	for (int i = 0; i < 5; i++)
	{
		v[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += v[i];
	}

	std::cout << sum << std::endl;

}

