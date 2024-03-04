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
	~Vector() { delete[] elem; }						//delete allocated memory using destructor
	double& operator[](int i) { return elem[i]; }
	size_t size() const { return siz; }
};

class Container {
public:
	virtual double& operator[](int) = 0;
	virtual size_t size() const = 0;
	virtual ~Container() {};
};

class Vector_container : public Container {
	Vector v;
public:
	Vector_container(int s) : v(s) {};
	Vector_container(std::initializer_list<double>lst) : v{ lst } {};
	~Vector_container() {};

	double& operator[](int i) { return v[i]; }
	size_t size() const { return v.size(); }
};

void use(Container& container)
{
	int sum = 0;
	for (int i = 0; i < container.size(); i++)
	{
		sum += container[i];
	}
	std::cout << sum << std::endl;
}

int main()
{
	Vector_container vc{ 1, 2, 3, 4, 5 }; 
	use(vc);	//though parameter accept container class as virtual method implemented it works for child class
	return 0;
}

