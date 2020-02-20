#include "list.h"
#include <iostream>

List::List()
{
    top = 0;
}

bool List::isempty() const
{
    return top == 0;
}

bool List::isfull() const
{
    return top == MAX;
}

void List::showList() const
{
    if(top == 0)
        std::cout << "Lista pusta...\n";
    else
    {
        for(int i = 0; i < top; i++)
            std::cout << i << ". " << items[i] << std::endl;
    }
}

bool List::add(const Item & item) 
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else        
        return false;
    
}

void List::visit(void (*pf)(Item & item), int index)
{
    if(index <= top)
        (*pf)(items[index]);
        else
            std::cout << "Niepoprawny index...\n";
}