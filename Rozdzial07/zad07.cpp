// arrfun3.cpp -- funkcje obsługujące tablica i const
#include <iostream>
const int Max = 5;

// prototypy funkcji
double *fill_array(double ar[], int limit);
void show_array(const double ar[], double * end_pt);  // nie zmienia danych
void revalue(double r, double ar[], double * end_pt);

int main()
{
    using namespace std;
    double properties[Max];

    double *end  = fill_array(properties, Max);
    cout << "Wartosc end: " << *(end-1) << endl;

    show_array(properties, end);
    if (*(end-1) > 0)
    {
        cout << "Podaj czynnik zmiany wartości: ";
        double factor;
        while (!(cin >> factor)) // nieliczbowa wartość na wejściu
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Niepoprawna wartość; podaj liczbę: ";
        }
        revalue(factor, properties, end);
        show_array(properties, end);
    }
    cout << "Gotowe.\n";
    cin.get();
    cin.get();
    return 0;
}

double *fill_array(double ar[], int limit)
{
    using namespace std;
    double temp;
    int i;
    for (i = 0; i < limit; i++)
    {
        cout << "Podaj wartość nr " << (i + 1) << ": ";
        cin >> temp;
        if (!cin)    // błędne dane
        {
            cin.clear();
            //while (cin.get() != '\n')
                //continue;
           cout << "Błędne dane, wprowadzanie danych przerwane.\n";
           break;
        }
        else if (temp < 0)     // nakaz zakończenia
            break;
        ar[i] = temp;
    }
    return &ar[i];
}

// poniższa funkcja może użyć tablicy, której adres przekazano
// w ar, ale nie może jej modyfikować
void show_array(const double ar[], double * end_pt)
{
   using namespace std;
   const double *pt;
   int i = 1;
   for (pt = ar; pt != end_pt; pt++, i++)
    {
        cout << "Nieruchomość nr " << i << ": ";
        cout << *pt << endl;
    }
}

// mnoży każdy element ar[] przez r
void revalue(double r, double ar[], double * end_pt)
{
	double *pt;
    for (pt = ar; pt != end_pt; pt++)
        *pt *= r;
}
