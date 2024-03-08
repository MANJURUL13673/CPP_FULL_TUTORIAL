#include <iostream>

class Vector {
private:
	double* elem;
	size_t siz;

public:
	Vector() : elem{ nullptr }, siz{ 0 } {}
	Vector(size_t s) : elem{ new double[s] }, siz{ s } { }	//here initialize the private elements outside of the bracket
	Vector(std::initializer_list<double>lst) : elem{ new double[lst.size()] }, siz{ lst.size() } {
		std::copy(lst.begin(), lst.end(), elem);
	}
	~Vector() { delete[] elem; }						//delete allocated memory using destructor
	double& operator[](int i) { return elem[i]; }
	size_t size() { return siz; }

	//Copy Constructor
	Vector(const Vector& a) : elem{ new double[a.siz] }, siz{ a.siz } {
		for (int i = 0; i < siz; i++) {
			elem[i] = a.elem[i];
		}
	}
	//Copy assignment
	Vector& operator=(const Vector& a) {
		elem = new double[a.siz];
		siz = a.siz;
		for (int i = 0; i < siz; i++)
		{
			elem[i] = a.elem[i];
		}
		return *this;

	}

	//Move operator
	Vector(Vector&& a) : elem{ a.elem }, siz{ a.siz } {
		a.elem = nullptr;
		a.siz = 0;
	}

	//Move assignment
	Vector& operator=(Vector&& a) {
		elem = a.elem;
		siz = a.siz;
		a.elem = nullptr;
		a.siz = 0;
	}
};

int main()
{
	Vector v = { 1, 2, 3, 4, 5 };
	
	Vector z1 = v;
	std::cout << z1[0] << " " << v[0] << std::endl;	//okay -> v copy data to z1

	Vector z2 = std::move(v);
	std::cout << z2[0] << std::endl;
	//std::cout << v[0] << std::endl;	//not okay-> because pointer move to z2

}

