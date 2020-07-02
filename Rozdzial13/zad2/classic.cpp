#include "classic.h"
#include <cstring>
#include <iostream>

Classic::Classic(char * s0, char * s1, char * s2, int n, double x) : Cd(s1, s2, n, x)
{
    len = strlen(s0);
    title = new char[len + 1];
    std::strcpy(title, s0);
}

Classic::~Classic()
{
    delete [] title;
}

Classic::Classic() : Cd()
{
    len = 4;
    // title = new char[1];
    // title[0] = '\0';
    title = nullptr;
}

Classic::Classic(const Classic & c) : Cd(c)
{
    len = c.len;
    title = new char [len + 1];
    std::strcpy(title, c.title);
}

Classic::Classic(const char * s1, const Cd & cd) : Cd(cd)
{
    len = strlen(s1);
    title = new char[len + 1];
    std::strcpy(title, s1);
}

Classic & Classic::operator=(const Classic & c) 
{
    if(this == &c)
        return *this;
    Cd::operator=(c);
    delete [] title;
    len = c.len;
    title = new char [len + 1];
    std::strcpy(title, c.title);
    return *this;
}

void Classic::Report() const
{
    Cd::Report();
    std::cout << "Title: " << title << "\n";
}