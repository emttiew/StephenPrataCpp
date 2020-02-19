#include <iostream>
#include <cctype>                // albo ctype.h
#include "stack.h"
int main()
{
    using namespace std;
    Stack st;                    // tworzy pusty stos
    char ch;
    Item po = { "Micheal Scott", 20};
    double sum = 0.0;
    cout << "Naciśnij D, aby wprowadzić nową płatność, \n"
        << "P, aby przetworzyć płatność, lub K, aby zakończyć.\n";
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
            case 'd': cout << "Podaj nową płatność: ";
                      cin >> po.payment;
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
                          sum += po.payment;
                          cout << "Dodano płatność " << po.payment << " do sumy należności, która wynosi: " << sum << endl;                          
                      }
                      break;
        }
        cout << "Naciśnij D, aby wprowadzić nową płatność, \n"
            << "P, aby przetworzyć płatność, lub K, aby zakończyć.\n";
    }
    cout << "Fajrant!\n";
    return 0;
}