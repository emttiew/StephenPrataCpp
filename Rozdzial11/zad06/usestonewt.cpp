#include <iostream>
using std::cout;
using std::endl;
#include "stonewt.h"


int main()
{
    const int ArrSize = 6;

    Stonewt st(11);
    Stonewt tab[ArrSize];
    tab[0] = 10;
    tab[1] = 11;
    tab[2] = 13;

    double temp_pounds;

    for (int i = 3; i < ArrSize; i++)
    {
        cout << "Podaj wagę dla obiektu nr " << (i + 1) << " Stonewt\n";
        std::cin >> temp_pounds;
        tab[i] = temp_pounds;
    }

    Stonewt min = tab[0];
    Stonewt max = tab[0];
    int count = 0;

    for (int i = 0; i < ArrSize; i++)
    {       
        max = (max > tab[i]) ? max : tab[i];
        min = (min < tab[i]) ? min : tab[i];
        if (tab[i] >= st)
            ++count;
    }
    cout << "Pierwsze 3 obiekty: \n";
    for (int i = 0; i < 3; i++)
    {
        cout << tab[i] << endl;
    }
    cout << "Najcięższy obiekt waży: " << max << endl;
    cout << "Najlżejszy obiekt waży: " << min << endl;
    cout << "Liczba obiektów o wadze większej lub równej obiektowi st (waga: " << st << ") to: " << count << endl;
    return 0; 

}