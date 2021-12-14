#include "Complex.h"
Complex Complex::operator+(const Complex &c)
{
	return Complex(this->real + c.real, this->imag + c.imag);
}
Complex Complex::operator-(const Complex &c)
{
	return Complex(this->real - c.real, this->imag - c.imag);
}
Complex Complex::operator*(const Complex &c)
{
	return Complex(this->real * c.real - this->imag * c.imag, this->real * c.imag + this->imag * c.real);
}
Complex Complex::operator/(const Complex &c)
{
	int deno = c.imag * c.imag + c.real * c.real;
	return Complex((this->real * c.real + this->imag * c.imag) / deno, (this->imag * c.real - this->real * c.imag) / deno);
}
ostream &operator<<(ostream &out, const Complex &c)
{
	out << c.real << "+-"[c.imag < 0] << c.imag * (c.imag < 0 ? -1 : 1) << "i";
	return out;
}
istream &operator>>(istream &in, Complex &c)
{
	char op, i;
	in >> c.real >> op >> c.imag >> i;
	return in;
}