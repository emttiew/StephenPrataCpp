// stacker.cpp -- test klasy Stack
#include <iostream>
#include <cctype>                // albo ctype.h
#include "stack.h"
int main()
{
    using namespace std;
    Stack st;                    // tworzy pusty stos        
    char ch;
    unsigned long po;
    int size;
    
    cout << "Naciśnij D, aby wprowadzić deklarację, \n"
        << "P, aby przetworzyć deklarację, lub K, aby zakończyć.\n";
    while (cin >> ch && toupper(ch) != 'K')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'D':
            case 'd': cout << "Podaj numer nowej deklaracji: ";
                      cin >> po;
                      if (st.isfull())
                          cout << "Stos pełen!\n";
                      else
                          st.push(po);
                      break;
            case 'P':
            case 'p': if (st.isempty())
                          cout << "Stos pusty!\n";
                      else {
                          st.pop(po);
                          cout << "Deklaracja nr" << po << " zdjęta\n";
                      }
                      break;
        }
        cout << "Naciśnij D, aby wprowadzić deklarację, \n"
            << "P, aby przetworzyć deklarację, lub K, aby zakończyć.\n";
    }
    cout << "Fajrant!\n";
    cout << "Wypełniony stos domyślny: \n";
    cout << st;
    cout << "Wprowadź rozmiar nowego stosu: \n";
    cin >> size;
    Stack st2(size);
    cout << "Wypełnianie nowego stosu...\n";
    for (int i = 0; i < size; i++)
    {
        st2.push(i+1);
    }
    
    cout << "Nowy stos: \n";
    cout << st2;

    cout << "Kopiowanie nowego stosu do stosu domyślnego: \n";
    st = st2;
    cout << "Stos domyślny:\n" << st;

    cout << "Deklarowanie 3 stosu stosem domyślnym:\n";
    Stack st3(st);
    cout << "Stos 3: \n";
    cout << st3;

    return 0;
}

