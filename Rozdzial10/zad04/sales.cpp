#include "sales.h"
#include <iostream>

namespace SALES {
    Sales::Sales(){      
        int i = 0;
        std::cout << "Wprowadź wartości sprzedaży z 4 kwartałów:\n";
        while (std::cin && i < QUARTERS){
            std::cin >> sales[i];
            i++;
        }
        _average = sales[0];
        _max = sales[0];
        _min = sales[0];
        for(i = 1; i < QUARTERS; i++)
        {
            _average += sales[i];
            _max = (_max > sales[i]) ? _max : sales[i];
            _min = (_min < sales[i]) ? _min : sales[i];
        }
        _average /= QUARTERS;
    }

    Sales::Sales(const double ar[], int n){
        double max, min = *ar;
        double average = 0.0;

        if (n < QUARTERS){
            for (int i = n; i < QUARTERS; i++){
                    sales[n-1] = 0.0;
            }
        }
        for (int i = 0; i < n; i++){
            sales[i] = ar[i];
            max = (max > ar[i]) ? max : ar[i];
            min = (min < ar[i]) ? min : ar[i];
            average += ar[i];
        }
        _average = average / QUARTERS; // nie sprecyzowane z czego ma liczyć średnią - ar[] czy s.sales - wybrałem s.sales
        _max = max;
        _min = min;
    }

    void Sales::showSales() const{
        using std::cout;
        using std::endl;
        cout << "Zawartość sturktry:\n";
        cout << "Tablica sales:" << endl;
        for (int i = 0; i < QUARTERS; i++)
            cout << (i + 1) << ". " << sales[i] << endl;
        cout << "Wartość minimalna: " << _min << endl;
        cout << "Wartość maksymalna: " << _max << endl;
        cout << "Wartość średnia: " << _average << endl;
    }

}