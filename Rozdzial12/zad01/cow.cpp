#include "cow.h"
#include <string.h>
#include <iostream>

using std::cout;
using std::endl;

Cow::Cow()
{
    strcpy(name, "Brak");
    hobby = nullptr;
    weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
    if (strlen(nm) < 20) 
        cout << "Za długie imie... możliwa utrata części danych.\n";
    strcpy(name, nm);
   
    hobby = new char[strlen(ho) + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow &c)
{
    strcpy(name, c.name);
    weight = c.weight;
    hobby = new char[strlen(c.hobby) + 1]; 
    strcpy(hobby, c.hobby);
}

Cow::~Cow()
{
    delete [] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
    if(this == &c)
        return *this;
    strcpy(name, c.name);
    weight = c.weight;
    delete [] hobby;
    hobby = new char[strlen(c.hobby) + 1];
    strcpy(hobby, c.hobby);
    return *this;
}

void Cow::ShowCow() const
{
    cout << "Imię krowy: " << name << endl;
    cout << "Hobby krowy: " << (nullptr == hobby ? "Brak" : hobby) << endl;
    cout << "Waga krowy: " << weight << endl;
}