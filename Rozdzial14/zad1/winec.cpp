#include "winec.h"
#include <iostream>

void Wine::GetBottles()
{
    std::cout << "Podaj dane o winie " << label << " dla "
              <<  no_years << " roczników:\n";

    for(int i = 0; i < no_years; i++)
    {   
        std::cout << "Podaj rocznik:\n";
        std::cin >> vintage[i];
        std::cout << "Podaj liczbę butelek:\n";
        std::cin >> bottles[i];
    }
    shelf.first() = vintage;
    shelf.second() = bottles;
}

const int Wine::sum() const
{
    return bottles.sum();
}

void Wine::Show() const
{
    std::cout << "Wino: " << label << "\n" 
              << '\t' << "Rocznik\tButelki\n";
    for(int i = 0; i < no_years; ++i)
    {
        std::cout << "\t" << vintage[i] << "\t" << bottles[i] << "\n";
    }    
}