#include <iostream>
#include "list.h"

void inline foo (Item & x) { x *= x ;}
void inline bar (Item & x) { x += x ;}
void set_item(Item *, int);

int main()
{
    using std::cout;
    using std::endl;

    List list;
    Item q = 20;
    Item a[10];
    cout << "Lista zaraz po utworzeniu: \n";
    list.showList();
    cout << "Dodaję 20 jako pierwszy element: \n";
    list.add(q);
    list.showList();
    cout << "Modyfikuję element 0 funkcją foo(x^2):\n";
    list.visit(foo, 0);
    list.showList();

    cout << "Wypelniam listę 10 wartościami\n";
    set_item(a, 10);
    for (int i = 0; i < 10; i++)
    {
        if(!list.isfull())
            list.add(a[i]);
            else 
                cout << "Próba dodania wartości o indeksie " << (i + 1) << " nie powiodła się.\nLista pełna!\n";
    }
    
    list.showList();

    cout << "Modyfikuje element o indeksie 5 funkcją bar(x+x): \n";
    list.visit(bar, 5);
    list.showList();

    return 0;
}

void set_item(Item * item, int n)
{
    for(int i = 0; i < n; i++)
        item[i] = (i + 1)*2;
}