// stack.cpp -- metody klasy stosu
#include "stack.h"
Stack::Stack(int n)  : top(0), size(n)        // tworzy pusty stos
{
    pitems = new Item [size];
}

Stack::Stack(const Stack & st) : top(st.top), size(st.size)
{
    pitems = new Item [size];
    for (int i = 0; i < size; i++)
    {
        pitems[i] = st.pitems[i];
    }
}

Stack::~Stack()
{
    delete [] pitems;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == size;
}

bool Stack::push(const Item & item)
{
    if (top < size)
    {
        pitems[top++] = item;
        return true;
    }
    else
        return false;
}

bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = pitems[--top];
        return true;
    }
    else
        return false;
}

Stack & Stack::operator=(const Stack & st)
{
    if (this == &st)
        return *this;
    delete [] pitems;
    size = st.size;
    pitems = new Item [size];
    for (int i = 0; i < size; i++)
    {
        pitems[i] = st.pitems[i];
    }
    return *this;
}

std::ostream & operator<<(std::ostream & os, const Stack & st)
{
    for (int i = 0; i < st.size; i++)
    {
        os << st.pitems[i] << '\n';
    }
    return os;
}