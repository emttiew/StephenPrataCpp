#include <iostream>
#include <fstream>
#include <string>

int main(int arg, char * argv[])
{
    std::ifstream infile;
    std::ofstream outfile;
    char ch;

    infile.open(argv[1]);
    if(!infile.is_open())
    {
        std::cerr << "Nie można otworzyć plku " << argv[1] << '\n';
        exit(EXIT_FAILURE);
    }
    outfile.open(argv[2]);
    if(!outfile.is_open())
    {
        std::cerr << "Nie można otworzyć plku " << argv[2] << '\n';
        exit(EXIT_FAILURE);
    }

    while(infile.get(ch))
        outfile.put(ch);    
    
    infile.close();
    outfile.close();
    return 0;
}