#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf & g)
{
	using std::cout;
	using std::cin;
	using std::endl;
	char next;
	cout << "Podaj nazwisko: \n";
	cin.get(g.fullname, Len);
	if (g.fullname[0] == '\0')
	{
		cin.get(next);
		while (next != '\n')       // wiersz nie zmieścił się w buforze
		            cin.get(next); // porzucenie reszty znaków z wejścia
		cin.clear(); // czyszczenie flag
		cin.get();
		return 0;
	}
	else
	{
		while (cin.get() != '\n')
					continue; // czyszczenie wiersza
		cout << "Podaj wartość handicapu: \n";
		if(!(cin >> g.handicap))
			g.handicap = 0;
		cin.get();
		return 1;
	}


	if (g.fullname)
		return 1;
	else
		return 0;
}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf & g)
{
	std::cout << "Nazwisko: " << g.fullname << std::endl;
	std::cout << "Handicap: " << g.handicap << std::endl;
}
