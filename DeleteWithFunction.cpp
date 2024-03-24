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
	Vector(const Vector& a) = delete;	//delete the default constructor implementation, must be need implemenation, otherwise show compilation error
	//Copy assignment
	Vector& operator=(const Vector& a) = delete;

	//Move operator
	Vector(Vector&& a) = delete;

	//Move assignment
	Vector& operator=(Vector&& a) = delete;
};

int main()
{
	Vector v = { 1, 2, 3, 4, 5 };

	//without delete that will show runtime error;
	// but with delete that shows compilation error
	//Vector z1 = v;
	//std::cout << z1[0] << " " << v[0] << std::endl;	//okay -> v copy data to z1

	// same for move function
	//Vector z2 = std::move(v);
	//std::cout << z2[0] << std::endl;
	//std::cout << v[0] << std::endl;	//not okay-> because pointer move to z2

}
