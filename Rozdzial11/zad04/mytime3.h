// mytime3.h -- klasa Time z funkcjami zaprzyjaźnionymi
#ifndef MYTIME3_H_
#define MYTIME3_H_
#include <iostream>

using std::ostream;

class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h, int m = 0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h = 0, int m = 0);
        const friend Time operator+(const Time & t, const Time & d);
        const friend Time operator-(const Time & t, const Time & d);
        const friend Time operator*(double n, const Time & t);
        friend Time operator*(const Time & t, double m)
         { return m * t; } // definicja miejscowa (inline)
        friend ostream & operator<<(ostream & os, const Time & t);
};
#endif

