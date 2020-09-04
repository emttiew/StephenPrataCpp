// autor podał w zadaniu listing nr 16.5, ale do opisu zadania pasuje listing 16.15
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>

int main()
{
    auto outint = [](int n){ std::cout << n << " "; };

    int vals[10] = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    // std::list<int> yadayada; (vals, vals + 10);
    // std::list<int> etcetera; (vals, vals + 10);
    // w C++11 można alternatywnie użyć:
    std::list<int> yadayada = {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    std::list<int> etcetera {50, 100, 90, 180, 60, 210, 415, 88, 188, 201};
    std::cout << "Oryginalne listy:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    std::cout << std::endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    std::cout << std::endl;
    yadayada.remove_if([](int n){return n > 100;});             // używa nazwanego obiektu funkcyjnego
    etcetera.remove_if([](int n){return n > 200;}); // tworzy obiekt funkcyjny
    std::cout << "Przycięte listy:\n";
    for_each(yadayada.begin(), yadayada.end(), outint);
    std::cout << std::endl;
    for_each(etcetera.begin(), etcetera.end(), outint);
    std::cout << std::endl;

    return 0;
}

