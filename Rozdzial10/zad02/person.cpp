#include "person.h"
#include <cstring>
#include <iostream>

Person::Person(const std::string & ln, const char * fn ){
    lname = ln;
    strcpy(fname , fn);
}

void Person::Show() const { // w kolejności imię nazwisko
    using std::cout;
    using std::endl;
    cout << "Imię: " << lname << endl;
    cout << "Nazwisko: " << fname << endl;
}

void Person::FormalShow() const {
    using std::cout;
    using std::endl;
    cout << "Nazwisko: " << fname << endl;
    cout << "Imie:" << lname << endl;
}