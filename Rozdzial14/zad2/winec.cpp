#include "winec.h"
#include <iostream>

void Wine::GetBottles()
{
    std::cout << "Podaj dane o winie " << (const std::string &) *this << " dla "
              <<  no_years << " roczników:\n";

    for(int i = 0; i < no_years; i++)
    {   
        std::cout << "Podaj rocznik:\n";
        std::cin >> shelf.first()[i];
        std::cout << "Podaj liczbę butelek:\n";
        std::cin >> shelf.second()[i];
    }    
}

const int Wine::sum() const
{
    return shelf.second().sum();
}

void Wine::Show() const
{
    std::cout << "Wino: " << (const std::string &) *this << "\n" 
              << '\t' << "Rocznik\tButelki\n";
    for(int i = 0; i < no_years; ++i)
    {
        std::cout << "\t" << shelf.first()[i] << "\t" << shelf.second()[i] << "\n";
    }    
}