#include <string>

#ifndef PERSON_H_
# define PERSON_H_

class Person
{
	static const int LIMIT = 256;
    std::string lname;
    char fname[LIMIT];
  public:
    Person() { lname = ""; fname[0] = '\0'; };
    Person(const std::string & ln, const char * fn = "HejTy");
// poniższe metody wyświetlają imię i nazwisko
    void Show() const; // w kolejności imię nazwisko
    void FormalShow() const; // w kolejności nazwisko imię
};


#endif
