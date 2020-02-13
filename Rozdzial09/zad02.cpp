// static.cpp -- stosowanie lokalnej zmiennej statycznej
#include <iostream>
#include <string>
// stałe:
const int ArSize = 10;
using std::string;
// prototyp funkcji:
void strcount(const string & str);

int main()
{
    using namespace std;
    string input;

    cout << "Wprowadź wiersz:\n";
    getline(cin, input);
    while (input != "")
    {
    	strcount(input);
        cout << "Wprowadź następny wiersz (wiersz pusty kończy wprowadzanie):\n";
        getline(cin, input);
    }
    cout << "Koniec\n";
    return 0;
}

void strcount(const string & str)
{
    using namespace std;
    static int total = 0;          // statyczna zmienna lokalna

    cout << "\"" << str << "\" zawiera ";
    total += str.size();
    cout << str.size() << " znaków\n";
    cout << "Łącznie "<< total << " znaków\n";
}
