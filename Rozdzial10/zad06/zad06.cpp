#include "move.h"
#include <iostream>

int main()
{
    Move obj1( 21.1, 22.2);
    Move obj2( 10, 10);

    std::cout << "Objekt pierwszy: \n";
    obj1.showmove();
    std::cout << "Obiekt drugi: \n";
    obj2.showmove();
    //dodawanie        
    obj2 = obj1.add(obj2);
    std::cout << "Objekt pierwszy po operacji dodawania: \n";
    obj1.showmove();
    std::cout << "Obiekt drugi po operacji dodwania: \n";
    obj2.showmove();
    std::cout << "Rest objektu 2: \n";
    obj2.reset(0 , 0);
    std::cout << "Obiekt drugi po resecie wartościami 0, 0: \n";
    obj2.showmove();


    return 0;
}