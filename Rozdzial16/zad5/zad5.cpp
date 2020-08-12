#include <iostream>
#include <algorithm>
#include <list>

template <class T>
int reduce(T ar[], int n);

int main()
{   
    const int SIZE = 8;
    long ar[SIZE] = {100, 22, 13, 47, 25, 96, 22, 100};
    std::string ar2[SIZE] = { "maslo", "dzem", "kakao", "maslo", "sliwki", "kompot", "kakao", "aronia"};
    std::cout << "LONG\n";
    for(auto a : ar)
        std::cout << a << '\n';
    std::cout << "\nSTRING\n";
    for(auto a : ar2)
        std::cout << a << '\n';
    int new_size_ar1 = reduce(ar, SIZE);
    int new_size_ar2 = reduce(ar2, SIZE);
    std::cout << '\n';
    for(int i = 0; i < new_size_ar1; i++)
        std::cout << ar[i] << '\n';
    std::cout << '\n';
    for(int i = 0; i < new_size_ar2; i++)
        std::cout << ar2[i] << '\n';
    return 0;
}

template <class T>
int reduce(T ar[], int n)
{    
    std::list<T> list;
    list.insert(list.begin(), ar, ar + n);
    list.sort();
    list.unique();
    std::copy(list.begin(), list.end(), ar);
    return list.size();
}