// randwalk.cpp -- test klasy Vector
// kompilować z plikiem vect.cpp
#include <iostream>
#include <cstdlib>    // prototypy funkcji rand() i srand()
#include <ctime>      // prototyp funkcji time()
#include "vect.h"
#include <fstream>

int main()
{
    using namespace std;

    ofstream myfile;
	myfile.open("zad01.txt");

    using VECTOR::Vector;
    srand(time(0));   // inicjalizacja generatora liczb pseudolosowych
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;
    double dstep;
    cout << "Podaj dystans do przejścia (k, aby zakończyć): ";
    while (cin >> target)
    {
        cout << "Podaj długość kroku: ";
        if (!(cin >> dstep))
            break;
        
        myfile << steps << ": " << result << endl;

        while (result.magval() < target)
        {
            direction = rand() % 360;
            step.reset(dstep, direction, Vector::POL);
            result = result + step;
            steps++;

            myfile << steps << ": " << result << endl;
        }
        myfile << "Po " << steps << " krokach delikwent "
            "osiągnął położenie:\n";
        myfile << result << endl;
        result.polar_mode();
        myfile << " czyli\n" << result << endl;
        myfile << "Średnia długość kroku pozornego = "
            << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Podaj dystans do przejścia (k, aby zakończyć): ";
    }
    cout << "Koniec!\n";
    cin.clear();
    while (cin.get() != '\n')
        continue;
    
    myfile.close();
    return 0;
}

