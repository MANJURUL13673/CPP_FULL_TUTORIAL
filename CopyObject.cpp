#include <iostream>

class Vector {
private:
	double* elem;
	size_t siz;

public:
	Vector(size_t s) : elem{ new double[s] }, siz{ s } { }	//here initialize the private elements outside of the bracket
	Vector(std::initializer_list<double>lst) : elem{ new double[lst.size()] }, siz{ lst.size() } {
		std::copy(lst.begin(), lst.end(), elem);
	}
	/*
		copy consturctor needed to copy without same referrence
	*/
	Vector(const Vector& a) : elem{ new double[a.siz] }, siz{ a.siz } {
		for (int i = 0; i < siz; i++)
		{
			elem[i] = a.elem[i];
		}
	}
	~Vector() { delete[] elem; }						//delete allocated memory using destructor
	Vector& operator=(const Vector& a) {
		elem = new double[a.siz];
		siz = a.siz;
		for (int i = 0; i < siz; i++)
		{
			elem[i] = a.elem[i];
		}
		return *this;
	}
	double& operator[](int i) { return elem[i]; }
	size_t size() const { return siz; }
};

int main()
{
	Vector v{ 1, 2, 3, 4, 5 }; 
	/*
		without assignment operator or copy constructor that is bad copy
		both v2 and v points same location so if changing value with v2 affect also v values
	*/
	/*Vector v2 = v;
	v2[0]++;
	std::cout << v[0] << std::endl;*/

	//now copy constructor and operator = overloading added so no referrence at same location
	Vector v2(v);
	Vector v3 = v;

	v2[0]++;
	v3[0]++;

	std::cout << v[0] << std::endl;	//as copy constructor and = overloading added no same referrencing and it gives the same value like initialization

	return 0;
}

