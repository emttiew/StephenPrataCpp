#include "dma.h"
#include <memory>


const int LIMIT = 4;

int main()
{
    // baseDMA * objects[LIMIT];
    std::shared_ptr<baseDMA> objects[LIMIT];
    char temp[20], temp_child[20];
    int rating, kind;
    
    for (int i = 0; i < LIMIT; i++)
    {
        std::cout << "Podaj etykietę: " << "\n";
        std::cin >> temp;
        std::cout << "Podaj klasę: " << "\n";
        std::cin >> rating;
        std::cout << "Wpisz 1 dla klasy hasDMA, lub 2 dla lacksDMA: " << "\n";
        while(std::cin >> kind && (kind != 1 && kind != 2))
            std::cout << "Wpisz 1 lub 2: ";
        if(kind == 1)
        {
            std::cout << "Podaj styl: " << "\n";
            std::cin >> temp_child;
            objects[i] = std::make_shared<hasDMA>(temp_child, temp, rating); 
        } else {
            std::cout << "Podaj kolor: " << "\n";
            std::cin >> temp_child;
            objects[i] = std::make_shared<lacksDMA>(temp_child, temp, rating);
        }
        while (std::cin.get() != '\n')
            continue;
            
    }

    std::cout << "\n";
    for (auto x : objects)
    {
        x->View();
    }
    
    
}