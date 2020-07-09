// workmi.cpp -- dziedziczenie wielokrotne
// kompilacja z plikiem workermi.cpp
#include <iostream>
#include <cstring>
#include "BadDude.hpp"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Person * lolas[SIZE];
    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Podaj kategorię osoby:\n"
            << "g: Gunslinger  p:PokerPlayer  "
            << "b: BadDude  w:wyjście\n";
        cin >> choice;
        while (strchr("gpbw", choice) == NULL)
        {
            cout << "Wpisz g, p, b lub w: ";
            cin >> choice;
        }
        if (choice == 'w')
            break;
        switch(choice)
        {
            case 'g': lolas[ct] = new Gunslinger;
                      break;
            case 'p': lolas[ct] = new PokerPlayer;
                      break;
            case 'b': lolas[ct] = new BadDude;
                      break;
        }
        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nLista osób:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }
    for (i = 0; i < ct; i++)
        delete lolas[i];
    cout << "Koniec.\n";
    return 0;
}

