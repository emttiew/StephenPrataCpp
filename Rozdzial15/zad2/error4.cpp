// error4.cpp -- używa klas wyjątków
#include <iostream>
#include <cmath> // lub math.h; użytkownicy systemu UNIX mogą potrzebować opcji -lm
#include <stdexcept>
// prototypy funkcji
double hmean(double a, double b);
double gmean(double a, double b);
int main()
{
    using std::cout;
    using std::cin;
    using std::endl;

    double x, y, z;

    cout << "Podaj dwie liczby: ";
    while (cin >> x >> y)
    {
        try {      // początek bloku try
            z = hmean(x, y);
            cout << "Średnia harmoniczna liczb " << x << " i " << y
                << " wynosi " << z << endl;
            cout << "Średnia geometryczna liczb " << x << " i " << y
                << " wynosi " << gmean(x, y) << endl;
            cout << "Podaj kolejną parę liczb <w, aby wyjść>: ";
        }   // koniec bloku try
        catch (std::invalid_argument & bg)   // początek bloku catch
        {
            cout << bg.what() << '\n';
            cout << "Spróbuj ponownie.\n";
            continue;
        }
        catch (std::domain_error & hg)
        {
            cout << hg.what() << '\n';           
            cout << "Niestety, to koniec zabawy.\n";
            break;
        } // koniec bloku catch
    }
    cout << "Koniec\n";
    return 0;
}

double hmean(double a, double b) 
{
    if (a == -b)
        throw std::invalid_argument("Błąd w hmean(): suma liczb nie może wynosić 0");
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw std::domain_error("Błąd w gmean(): obie wartości muszą być nieujemne");
    return std::sqrt(a * b);
}

