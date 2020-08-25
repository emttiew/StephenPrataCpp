#include <iostream>
#include <fstream>

int main(int arg, char * argv[])
{
    std::ifstream infile_1;
    std::ifstream infile_2;
    std::ofstream outfile;
    char ch;

    infile_1.open(argv[1]);
    if(!infile_1.is_open())
    {
        std::cerr << "Nie można otworzyć plku " << argv[1] << '\n';
        exit(EXIT_FAILURE);
    }
    infile_2.open(argv[2]);
    if(!infile_2.is_open())
    {
        std::cerr << "Nie można otworzyć plku " << argv[2] << '\n';
        exit(EXIT_FAILURE);
    }
    outfile.open(argv[3]);
    if(!outfile.is_open())
    {
        std::cerr << "Nie można otworzyć plku " << argv[3] << '\n';
        exit(EXIT_FAILURE);
    }

    while(!infile_1.eof() || !infile_2.eof())
    {       
        while(infile_1.get(ch) && ch != '\n')
            outfile.put(ch);
        if (!infile_1.eof())
            outfile.put(' ');        
    
        while(infile_2.get(ch) && ch != '\n')
            outfile.put(ch);        
        outfile.put('\n');        
    }
   
    
    infile_1.close();
    infile_2.close();
    outfile.close();
    return 0;
}