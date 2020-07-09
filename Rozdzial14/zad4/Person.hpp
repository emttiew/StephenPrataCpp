#ifndef PERSON_HPP_
#define PERSON_HPP_

#include <iostream>

class Person
{
private:
    std::string fullname;
public:
    Person(char * s = "brak") : fullname(s) {}
    virtual ~Person() = 0;
    virtual void Show() const { std::cout << "FullName: " << fullname << "\n";}
    virtual void Set();
};

void Person::Set()
{
    std::cout << "Podaj imię oraz nazwisko: \n";
    getline(std::cin, fullname);
}

#endif