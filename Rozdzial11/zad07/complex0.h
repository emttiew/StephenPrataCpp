#ifndef COMPLEX0_H_
#define COMPLEX0_H_

#include <iostream>

class complex 
{
private:
    double real;
    double imaginary;
public:
    complex(double rl = 0, double im = 0);
    ~complex();
    complex operator~() const;
    friend complex operator+(const complex & c1, const complex & c2);
    friend complex operator-(const complex & c1, const complex & c2);
    friend complex operator*(const complex & c1, const complex & c2);
    friend complex operator*(const complex & c, const double d);
    friend complex operator*(const double d, const complex & c);
    friend std::ostream & operator<<(std::ostream & os, const complex & c);
    friend std::istream & operator>>(std::istream & is, complex & c);
};

#endif