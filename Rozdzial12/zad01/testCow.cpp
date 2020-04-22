#include "cow.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
    Cow cow1;
    Cow cow2("Czarek", "Jedzenie", 200);
    cout << "Krowa domyślna: \n";
    cow1.ShowCow();
    cout << "Krowa z parametrami: \n";
    cow2.ShowCow();
    cout << "Krowa domyślna po przypisaniu cow2 do cow1\n";
    cow1 = cow2;
    cow1.ShowCow();
    cout << "Inicjalizacja cow3(domyślna) obiektem cow2: \n";
    Cow cow3(cow2);
    cow3.ShowCow();
    return 0;
}