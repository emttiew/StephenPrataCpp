#include "plorg.h"
#include <iostream>

int main()
{
    using std::cout;
    using std::endl;
    using std::cin;

    Plorg one;
    int food;
    int kanapka = 100;
    cout << "Pierwszy plorg: \n";
    one.show();
    cout << "Plorg dostał kanapkę\n";
    one.set_factor(kanapka);
    one.show();

    char two_name[19];
    char three_name[21];
    cout << "Podaj imię Plorga: \n";
    cin >> two_name;
    cout << "Podaj imię kolejnego: \n";
    cin >> three_name;
    cout << "Podaj jego współczynik sytości: \n";
    cin >> food;
    Plorg two(two_name);
    Plorg three(three_name, food);

    two.show();
    three.show();

}