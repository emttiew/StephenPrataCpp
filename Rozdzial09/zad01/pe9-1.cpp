#include <iostream>
#include "golf.h"


int main(){
	const int Len = 3;

	golf andy;
	setgolf(andy, "Andy Berdnard", 12);
	showgolf(andy);
	golf tab[Len];
	int players = 0;
	int new_hc;

	std::cout << "Ustaw do 3 nowych graczy: \n";
	while( players < Len && setgolf(tab[players]))
	{
		players++;
	}
	std::cout << "Nowi gracze: \n";
	for ( int i = 0; i < players; i++ )
	{
		showgolf(tab[i]);
	}
	std::cout << "Zmień wartość handicapu dla Angiego. \n"
			"Podaj warość: \n";
	std::cin >> new_hc;
	handicap(andy, new_hc);
	std::cout << "Uaktualniony Andy: \n";
	showgolf(andy);

	return 0;
}
