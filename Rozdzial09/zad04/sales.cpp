#include <iostream>
#include "sales.h"

namespace SALES{

void setSales(Sales & s, const double ar[], int n){
	double max, min = *ar;
	double average = 0.0;

	if (n < QUARTERS){
		for (int i = n; i < QUARTERS; i++){
				s.sales[n-1] = 0.0;
		}
	}
	for (int i = 0; i < n; i++){
		s.sales[i] = ar[i];
		max = (max > ar[i]) ? max : ar[i];
		min = (min < ar[i]) ? min : ar[i];
		average += ar[i];
	}
	s.average = average / QUARTERS; // nie sprecyzowane z czego ma liczyć średnią - ar[] czy s.sales - wybrałem s.sales
	s.max = max;
	s.min = min;

}

void setSales(Sales & s){
    using std::cout;
    using std::cin;
    int i = 0;
    cout << "Wprowadź wartości sprzedaży z 4 kwartałów:\n";
    while (cin && i < QUARTERS){
        cin >> s.sales[i];
        i++;
    }
    s.average=s.sales[0];
    s.max = s.sales[0];
    s.min = s.sales[0];
    for(i = 1; i < QUARTERS; i++)
    {
        s.average += s.sales[i];
        s.max = (s.max > s.sales[i]) ? s.max : s.sales[i];
        s.min = (s.min < s.sales[i]) ? s.min : s.sales[i];
    }
    s.average /= QUARTERS;
}


void showSales(const Sales & s){
	using std::cout;
	using std::endl;
	cout << "Zawartość sturktry:\n";
	cout << "Tablica sales:" << endl;
	for (int i = 0; i < QUARTERS; i++)
		cout << (i + 1) << ". " << s.sales[i] << endl;
	cout << "Wartość minimalna: " << s.min << endl;
	cout << "Wartość maksymalna: " << s.max << endl;
	cout << "Wartość średnia: " << s.average << endl;
}
}
