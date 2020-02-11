// lotto.cpp -- prawdopodobieństwo wygranej
#include <iostream>
// Uwaga: w niektórych implementacjach C++ trzeba użyć typu double
//        zamiast long double.
long double probability(unsigned numbers, unsigned picks);
int main()
{
    using namespace std;
    double total, choices, power_ball;
    cout << "Podaj największą liczbę, jaką można wybrać, oraz\n"
            "liczbę skreśleń:\n";
    while ((cin >> total >> choices) && choices <= total)
    {
    	cout << "Podaj najwieksza liczbę powerball, jaka można wybrać: ";
    	cin >> power_ball;
        cout << "Szansa wygranej to jeden do ";
        cout << probability(total, choices)*probability(power_ball, 1.0);      // wyliczenie wyniku
        cout << ".\n";
        cout << "Następne dwie liczby (q, aby zakończyć): ";
    }
    cout << "do widzenia\n";
    return 0;
}

// Poniższa funkcja wylicza prawdopodobieństwo trafnego wybrania picks
// liczb spośród numbers możliwych.
long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;  // kilka zmiennych lokalnych
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
        result = result * n / p ;
    return result;
}
