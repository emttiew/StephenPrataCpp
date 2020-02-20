#include "plorg.h"
#include <iostream>
#include <cstring>

Plorg::Plorg()
{
    strcpy(name, "Plorga");
    full_factor = 50;
}

Plorg::Plorg(const char * str, const int f)
{
    int str_size = strlen(str) + 1;
    if(str_size > LIMIT)
        std::cout << "Podano za długie imie.\n";
    else
        strcpy(name, str);
    full_factor = f;
}

void Plorg::set_factor(const int f)
{
    full_factor = f;
}

void Plorg::show() const
{
    std::cout << "Imię: " << name << std::endl;
    std::cout << "Współczynnik sytości: " << full_factor << std::endl;
}