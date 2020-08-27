#include <fstream>
#include <iostream>
#include <memory>
#include <iomanip>
#include "emp.h"

const int MAX = 10;

void showMenu();

int main()
{
    std::shared_ptr<abstr_emp> pc[MAX];
    int count = 0;
    char ch;
    int classkind;

    std::ifstream fin;
    fin.open("list.dat");

    if(fin.is_open())
    {   
        while ((fin >> classkind).get(ch))
        {
            switch(classkind)
			{
				case abstr_emp::Employee:
					pc[count] = std::make_shared<employee>();
					pc[count++]->getall(fin);
					break;
				case abstr_emp::Manager:
					pc[count] = std::make_shared<manager>();
					pc[count++]->getall(fin);
					break;
				case abstr_emp::Fink:
					pc[count] = std::make_shared<fink>();
					pc[count++]->getall(fin);
					break;
				case abstr_emp::Highfink:
					pc[count] = std::make_shared<highfink>();
					pc[count++]->getall(fin);
					break;
				default:
					std::cerr << "Błąd przy tworzeniu obiektów z pliku" << '\n';
					break;
			}
        }
        std::cout << "Aktualna lista pracowników: " << '\n';
		for (int i = 0; i < count; i++)
		{
			pc[i]->ShowAll();
			std::cout << '\n';
		}
		fin.close();        
    }

    while (count < MAX)
	{
		showMenu();
		std::cin >> ch;
		std::cin.ignore(255, '\n');
		switch (ch)
		{
			case '1':
				pc[count] = std::make_shared<employee>();
				pc[count]->SetAll();
				count++;
				break;
			case '2':
				pc[count] = std::make_shared<manager>();
				pc[count]->SetAll();
				count++;
				break;
			case '3':
				pc[count] = std::make_shared<fink>();
				pc[count]->SetAll();
				count++;
				break;
			case '4':
				pc[count] = std::make_shared<highfink>();
				pc[count]->SetAll();
				count++;
				break;
			case 'q':
				break;
			default:
				std::cout << "Błąd podczas podczas wprowadzania nowych danych'\n";
				continue;
				break;
		}
		if (ch == 'q')
			break;
	}
	std::ofstream fout;
	fout.open("list.dat");
	if(!fout.is_open())
	{
		std::cerr << "Nie można otworzyć pliku list.dat" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "Uaktualniona lista: \n";
	for(int i = 0; i < count; i++)
	{
		pc[i]->ShowAll();
		std::cout << '\n';
		pc[i]->writeall(fout);
	}
	fout.close();
    
    return 0;
}

void showMenu()
{
    std::cout << "Wybierz pracownika, którego chcesz dodać: \n";
    std::cout << "1. Pracownik" << std::setw(20) << "2. Manager" << std::setw(20) << "3. Fink\n"
              << "4. Highfink\nWciśnij 'q', aby wyjść\n";  
}