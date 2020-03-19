// mytime3.cpp -- implementacja metod klasy Time
#include "mytime3.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m )
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

const Time operator+(const Time & t, const Time & d) 
{
    Time sum;
    sum.minutes = d.minutes + t.minutes;
    sum.hours = d.hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

const Time operator-(const Time & t, const Time & d)
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = d.minutes + 60 * d.hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

const Time operator*(double mult, const Time & t)
{
    Time result;
    long totalminutes = t.hours * mult * 60 + t.minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

ostream & operator<<(ostream & os, const Time & t)
{
    os << t.hours << " godzin, " << t.minutes << " minut";
    return os;
}

