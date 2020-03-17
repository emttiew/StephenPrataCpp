// randwalk.cpp -- test klasy Vector
// kompilować z plikiem vect.cpp
#include <iostream>
#include <cstdlib>    // prototypy funkcji rand() i srand()
#include <ctime>      // prototyp funkcji time()
#include "vect.h"

int main()
{
    using namespace std;
    using VECTOR::Vector;
    srand(time(0));   // inicjalizacja generatora liczb pseudolosowych
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    unsigned long attempts;
    unsigned long min, max, sum = 0;

    cout << "Podaj dystans do przejścia (k, aby zakończyć): ";
    while (cin >> target)
    {
        cout << "Podaj długość kroku: ";
        if (!(cin >> dstep))
            break;

        cout << "Podaj ilość prób: ";
        if (!(cin >> attempts))
            break;

        for (int i = 0; i < attempts; i++) 
        {
            while (result.magval() < target)
            {
                direction = rand() % 360;
                step.reset(dstep, direction, Vector::POL);
                result = result + step;
                steps++;
            }
            if (i == 0)
                max = min = steps;

            if (steps > max)
				max = steps;
			if (steps < min)
				min = steps;

            sum += steps;            
            steps = 0;
            result.reset(0.0, 0.0);                      
        }
            cout << "Po " << attempts << " próbach minimalna ilość przebytych kroków to: " << min << endl;
            cout << "Maksymalna ilość kroków to: " << max << endl;
            cout << "Średnia ilość kroków potrzebna do przebycia zadanego dystansu: " << sum/attempts << endl;
            cout << "Podaj dystans do przejścia (k, aby zakończyć): ";
    }
    cout << "Koniec!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    return 0;
}

