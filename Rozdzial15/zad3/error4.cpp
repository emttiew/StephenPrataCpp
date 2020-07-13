// error4.cpp -- używa klas wyjątków
#include <iostream>
#include <cmath> // lub math.h; użytkownicy systemu UNIX mogą potrzebować opcji -lm
#include <stdexcept>
// prototypy funkcji
double hmean(double a, double b);
double gmean(double a, double b);

class bad_hmean : public std::invalid_argument
{
private:
    int arg1, arg2;
public:
    bad_hmean(int a1, int a2, std::string s = "") : std::invalid_argument(s), arg1(a1), arg2(a2) {}
    void show() const;
};

class bad_gmean : public std::domain_error
{
private:
    int arg1, arg2;
public:
    bad_gmean(int a1, int a2, std::string s = "") : std::domain_error(s), arg1(a1), arg2(a2) {}
    void show() const;
};

void bad_hmean::show() const
{
    std::cout << "Funkcja hmean():\n";
    std::cout << "Niepoprawne argumenty: " << arg1 << " oraz: " << arg2 << '\n';
    std::cout << "Suma liczb nie może wynosić 0\n";
}

void bad_gmean::show() const
{
    std::cout << "Funkcja gmean():\n";
    std::cout << "Niepoprawne argumenty: " << arg1 << " oraz: " << arg2 << '\n';
    std::cout << "Obie wartości muszą być nieujemne\n";
}

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
        catch (std::exception & e)
        {
            if(typeid(bad_hmean &) == typeid(e))
            {
                bad_hmean & bh = dynamic_cast<bad_hmean &>(e);
                bh.show();
            }
            if(typeid(bad_gmean &) == typeid(e))
            {
                bad_gmean & gh = dynamic_cast<bad_gmean &>(e);
                gh.show();
            }
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
        throw bad_hmean(a, b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a, b);
    return std::sqrt(a * b);
}

