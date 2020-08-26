#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <fstream>

int main()
{
    std::ifstream lolek_file;
    std::ifstream bolek_file;
    std::ofstream common_friends;
    std::list<std::string> bolek_friends;
    std::list<std::string> lolek_friends;
    std::string name;

    bolek_file.open("bolek.dat");
    if(!bolek_file.is_open())
    {
        std::cerr << "Nie można otworzyć plku bolek.dat\n";
        exit(EXIT_FAILURE);
    }
    lolek_file.open("lolek.dat");
    if(!lolek_file.is_open())
    {
        std::cerr << "Nie można otworzyć plku lolek.dat\n";
        exit(EXIT_FAILURE);
    }
    
    while(!bolek_file.eof())
    {       
        getline(bolek_file, name);
        bolek_friends.push_back(name);
    }

    while(!lolek_file.eof())
    {       
        getline(lolek_file, name);
        lolek_friends.push_back(name);
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

    common_friends.open("bolilol.dat");

    std::cout << "\nWspólna lista przyjaciół Bolka i Lolka: \n";
    for(auto m : merged_friends)
    {
        common_friends << m << '\n';
        std::cout << m << '\n';
    }
        
    
    lolek_file.close();
    bolek_file.close();
    common_friends.close();
    return 0;
}