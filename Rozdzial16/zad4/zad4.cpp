#include <iostream>
#include <algorithm>
#include <list>

int reduce(long ar[], int n);

int main()
{   
    const int SIZE = 8;
    long ar[SIZE] = {100, 22, 13, 47, 25, 96, 22, 100};
    for(long a : ar)
        std::cout << a << '\n';
    int new_size = reduce(ar, SIZE);
    std::cout << '\n';
    for(int i = 0; i < new_size; i++)
        std::cout << ar[i] << '\n';
    return 0;
}

int reduce(long ar[], int n)
{    
    std::list<long> list;
    list.insert(list.begin(), ar, ar + n);
    list.sort();
    list.unique();
    std::copy(list.begin(), list.end(), ar);
    return list.size();
}