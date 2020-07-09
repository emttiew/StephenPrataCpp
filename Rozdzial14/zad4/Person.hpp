#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <iostream>

class Person
{
private:
    std::string fullname;
public:
    Person(char * s) : fullname(s) {}
    Person() {}
    virtual ~Person() {}
    virtual void Show() const { std::cout << "FullName: " << fullname << "\n";}
    virtual void Set();
};

void Person::Set()
{
    std::cout << "Podaj imię oraz nazwisko: \n";
    getline(std::cin, fullname);
}

#endif