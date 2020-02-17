#include <iostream>
#include "golf.h"


int main(){
	const int Len = 3;

	Golf andy("Andy Berdnard", 12);
	andy.showgolf();
	
	int new_hc;

	std::cout << "Ustaw do 3 nowych graczy: \n";
    Golf tab[Len];
	std::cout << "Nowi gracze: \n";
	for ( int i = 0; i < Len; i++ )
	{
		tab[i].showgolf();
	}
	std::cout << "Zmień wartość handicapu dla Angiego. \n"
			"Podaj warość: \n";
	std::cin >> new_hc;
	andy.handicap(new_hc);
	std::cout << "Uaktualniony Andy: \n";
	andy.showgolf();

	return 0;
}
