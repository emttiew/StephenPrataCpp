#include <iostream>
#include <cstring>
#include "golf.h"

Golf::Golf(const char * name, int hc)
{
	_handicap = hc;
	strcpy(fullname, name);
}

Golf::Golf()
{
	using std::cout;
	using std::cin;
	using std::endl;
	char next;
	cout << "Podaj nazwisko: \n";
	cin.get(fullname, Len);
	if (fullname[0] == '\0')
	{
		cin.get(next);
		while (next != '\n')       // wiersz nie zmieścił się w buforze
		            cin.get(next); // porzucenie reszty znaków z wejścia
		cin.clear(); // czyszczenie flag
		cin.get();		
	}
	else
	{
		while (cin.get() != '\n')
					continue; // czyszczenie wiersza
		cout << "Podaj wartość handicapu: \n";
		if(!(cin >> _handicap))
			_handicap = 0;
		cin.get();
	}
}

void Golf::handicap(int hc)
{
	_handicap = hc;
}

void Golf::showgolf() const
{
	std::cout << "Nazwisko: " << fullname << std::endl;
	std::cout << "Handicap: " << _handicap << std::endl;
}
