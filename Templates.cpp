#include <iostream>
#include <vector>

template<typename T>
class Vector {
private:
	T* elem;
	int siz;

public:
	Vector(int s) : elem{ new T[s] }, siz{ s } { }	//here initialize the private elements outside of the bracket
	~Vector() { delete[] elem; }						//delete allocated memory using destructor
	T& operator[](int i) { return elem[i]; }
	int size() { return siz; }
};

//multiple different typename is possible
template<typename Container, typename Value>
Value sumOfRange(const Container& c, Value v)
{
	for (auto x : c)
	{
		v += x;
	}
	return v;
}
int main()
{
	//all types are valid as template
	Vector<char>vc(5);
	Vector<int>vi(6);
	Vector<double>vd(8);

	std::vector<int>viS(6);	//use default vector, otherwise for Vector need to implement begin() and end() function also
	for (int i = 0; i < 6; i++)
	{
		viS[i] = i;
	}

	int sum = sumOfRange(viS, 0);
	std::cout << sum << std::endl;

}