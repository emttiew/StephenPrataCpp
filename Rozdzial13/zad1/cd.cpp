#include "cd.h"
#include <cstring>
#include <iostream>

Cd::Cd(char * s1, char * s2, int n, double x)
{
    selections = n;
    playtime = x;
    strcpy(performers, s1);
    strcpy(label, s2);    
}

Cd::Cd(const Cd & d)
{
    playtime = d.playtime;
    selections = d.selections;
    strcpy(performers, d.performers);
    strcpy(label, d.label);
}

Cd::Cd()
{
    selections = 0;
    playtime = 0;
    strcpy(performers, "default");
    strcpy(label, "default");
}

void Cd::Report() const
{
    std::cout << "Selections: " << selections << "\n";
    std::cout << "Playtime: " << playtime << "\n";
    std::cout << "Performers: " << performers << "\n";
    std::cout << "Label: " << label << "\n";
}

Cd & Cd::operator=(const Cd & d)
{
    if(this == &d)
        return *this;
    playtime = d.playtime;
    selections = d.selections;
    strcpy(performers, d.performers);
    strcpy(label, d.label);
    return *this;
}

Cd::~Cd()
{}