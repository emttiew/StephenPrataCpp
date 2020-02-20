#ifndef LIST_H_
#define LIST_H_

typedef unsigned long Item;

class List 
{
    enum { MAX = 10 };
    Item items[MAX];
    int top;
  public:
    List(); // tworzy pustą listę 
    bool isempty() const;
    bool isfull() const;
    void visit(void (*pf)(Item &), int); // odwiedza element listy i wykonuje na nim zadaną operację
    bool add(const Item &);
    void showList() const;
};

#endif