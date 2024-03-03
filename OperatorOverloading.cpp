#include <iostream>

class complex {
	double re, im;
public:
	complex(double r, double e) :re{ r }, im{ e } {}
	complex(double r) : re{ r }, im{ 0 } {}
	complex() : re{ 0 }, im{ 0 } {}

	double real() const { return re; }	//when object properties does not change in a function, const is using
	void real(double d) { re = d; }
	double image() const { return im; }
	void imag(double d) { im = d; }

	complex& operator+=(complex z);
	complex& operator-=(complex z);
	complex& operator*=(complex z);
	complex& operator/=(complex z);

	complex operator+(complex a);
	complex operator-(complex a);
	complex operator*(complex a);
	complex operator/(complex a);
};

complex& complex::operator+=(complex z) {
	re += z.re;
	im += z.im;
	return *this;
}

complex& complex::operator-=(complex z) {
	re -= z.re;
	im -= z.im;
	return *this;
}

complex& complex::operator*=(complex z) {
	re *= z.re;
	im *= z.im;
	return *this;
}

complex& complex::operator/=(complex z) {
	re /= z.re;
	im /= z.im;
	return *this;
}

complex complex::operator+(complex a) {
	complex temp;
	temp.re = re + a.re;
	temp.im = im + a.im;
	return temp;
}

complex complex::operator-(complex a) {
	complex temp;
	temp.re = re - a.re;
	temp.im = im - a.im;
	return temp;
}

complex complex::operator*(complex a) {
	complex temp;
	temp.re = re * a.re;
	temp.im = im * a.im;
	return temp;
}

complex complex::operator/(complex a) {
	complex temp;
	temp.re = re / a.re;
	temp.im = im / a.im;
	return temp;
}

int main()
{
	complex a{ 2.3, 2 };
	complex b{ (complex)1 / a };
	complex c{ a + b * complex{1, 2.3} };
	std::cout << c.real() << " " << c.image() << std::endl;
	return 0;
}