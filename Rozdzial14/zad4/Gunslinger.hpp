#ifndef GUNSLINGER_HPP_
#define GUNSLINGER_HPP_

#include "Person.hpp"

class Gunslinger : virtual public Person
{
private:
    double draw_time;
    int cut_count;
public:
    Gunslinger() : Person(), cut_count(0), draw_time(0) {}
    Gunslinger(char * s, double d, int c) : Person(s), draw_time(d), cut_count(c) {}
    const double Draw() const { return draw_time; }
    virtual void Show() const;
    void ShowComponents() const;
    void Set();
    void SetComponents();
    ~Gunslinger();
};

void Gunslinger::Show() const
{
    Person::Show();
    std::cout << "Czas wyciągania rewolweru: " << draw_time << "\n";
    std::cout << "Liczba nacięć na rewolwerze: " << cut_count << "\n";
}

void Gunslinger::ShowComponents() const
{
    std::cout << "Czas wyciągania rewolweru: " << draw_time << "\n";
    std::cout << "Liczba nacięć na rewolwerze: " << cut_count << "\n";
}

void Gunslinger::Set() 
{   
    Person::Set();    
    std::cout << "Podaj czas wyciągania rewolweru: \n";
    std::cin >> draw_time;
    std::cout << "Podaj ilość nacięć na rewolwerze: \n";
    std::cin >> cut_count;    
}

void Gunslinger::SetComponents()
{
    std::cout << "Podaj czas wyciągania rewolweru: \n";
    std::cin >> draw_time;
    std::cout << "Podaj ilość nacięć na rewolwerze: \n";
    std::cin >> cut_count; 
}

#endif