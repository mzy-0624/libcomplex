#ifndef COMPLEX_H
#define COMPLEX_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
class Complex
{
private:
    int real, imag;
public:
    Complex() = default;
    Complex(int real, int imag)
    {
        this->real = real;
        this->imag = imag;
    }
    int getReal(void)
    {
        return real;
    }
    int getImag(void)
    {
        return imag;
    }
    Complex operator+(const Complex &c);
    Complex operator-(const Complex &c);
    Complex operator*(const Complex &c);
    Complex operator/(const Complex &c);
    friend ostream &operator<<(ostream &out, const Complex &c);
    friend istream &operator>>(istream &in, Complex &c);
};
#endif