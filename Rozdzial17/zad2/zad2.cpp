#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::string filename;
    char ch;

    std::cout << "Podaj nazwę pliku: ";
    std::cin >> filename;

    std::ofstream fout(filename.c_str());
    if(!fout.is_open())
        std::cerr << "Błąd. Nie można otworzyć pliku.\n";
    std::cout << "Zacznij wypełniać plik ('ctrl + d' aby przerwać): \n";
    while(std::cin.get(ch))
        fout.put(ch);
    return 0;

}