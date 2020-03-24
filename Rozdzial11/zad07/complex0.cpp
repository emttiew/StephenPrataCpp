// complex0.cpp -- implementacje metod klasy complex0
#include "complex0.h"



complex::complex(double rl, double im)
{
    real = rl;
    imaginary = im;
}

complex operator+(const complex & c1, const complex & c2)
{
    complex sum;
    sum.real = c1.real + c2.real;
    sum.imaginary = c1.imaginary + c2.imaginary;
    return sum;
}

complex operator-(const complex & c1, const complex & c2)
{
    complex sub;
    sub.real = c1.real - c2.real;
    sub.imaginary = c1.imaginary - c2.imaginary;
    return sub;
}

complex operator*(const complex & c1, const complex & c2)
{
    complex multi;
    multi.real = (c1.real * c2.real) - (c1.imaginary * c2.imaginary);
    multi.imaginary = (c1.real * c2.imaginary) + (c1.imaginary * c2.real);
    return multi;
}

complex operator*(const double d, const complex & c)
{
    complex result;
    result.real = c.real * d;
    result.imaginary = c.imaginary * d;
    return result; 
}

complex operator*(const complex & c, const double d)
{
    return (d * c);
}

