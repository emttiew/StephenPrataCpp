#include <iostream>
#include "complex0.h"

using std::cout;
using std::cin;

int main() 
{
    complex a(3.0, 4.0);    // inicjalizacja wartością (3, 4i)
    complex c;
    cout << "Podaj liczbę zespoloną (k, aby zakończyć): \n";
    while (cin >> c)
    {
        cout << "c to " << c << '\n';
        cout << "sprzężona z c to " << ~c << '\n';
        cout << "a to " << a << '\n';
        cout << "a + c wynosi " << a + c << '\n';
        cout << "a - c wynosi " << a - c << '\n';
        cout << "a * c wynosi " << a * c << '\n';
        cout << "2 * c wynosi " << 2 * c << '\n';
        cout << "Podaj liczbę zespoloną (k, aby zakończyć): \n";
    }

    cout << "Gotowe!\n";
    return 0;

}