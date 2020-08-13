#include <iostream>
#include <algorithm>
#include <list>
#include <string>

int main()
{
    std::list<std::string> bolek_friends;
    std::list<std::string> lolek_friends;
    std::string name;

    std::cout << "Podaj listę przyjaciół Bolka: \n";
    getline(std::cin, name);
    while(name != "q")
    {
        if(name != "")
            bolek_friends.push_back(name);
        std::cout << "Aby przerwać wpisz 'q'\n";
        getline(std::cin, name);
    }

    std::cout << "Podaj listę przyjaciół Lolka: \n";
    getline(std::cin, name);
    while(name != "q")
    {
        if(name != "")
            lolek_friends.push_back(name);
        std::cout << "Aby przerwać wpisz 'q'\n";
        getline(std::cin, name);
    }
    
    bolek_friends.sort();
    lolek_friends.sort();
    std::cout << "Przyjaciele Bolka: \n";
    for(auto b : bolek_friends)
        std::cout << b << '\n';
    std::cout << "\nPrzyjaciele Lolka: \n";
    for(auto l : lolek_friends)
        std::cout << l << '\n';

    std::list<std::string> merged_friends;
    merged_friends.insert(merged_friends.begin(), bolek_friends.begin(), bolek_friends.end());
    merged_friends.insert(merged_friends.end(), lolek_friends.begin(), lolek_friends.end());
    merged_friends.sort();
    merged_friends.unique();

    std::cout << "\nWspólna lista przyjaciół Bolka i Lolka: \n";
    for(auto m : merged_friends)
        std::cout << m << '\n';
    return 0;
}