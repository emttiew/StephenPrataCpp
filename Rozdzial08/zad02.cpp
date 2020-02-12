#include <iostream>
#include <cstring>

struct Batonik
{
	char marka[40];
	double waga;
	int kalorie;
};

void obsluga_batona (Batonik & baton, const char * m = "Millennium Munch", const double w = 2.85, const int k = 350);


int main(){
	Batonik baton;
	std::cout << "Baton domyślny: \n";
	obsluga_batona(baton);
	double w;
	int k;
	char m[40];
	while(std::cin){
		std::cout << "\nPodaj markę batona: \n";
		std::cin >> m;
		std::cout << "Podaj wagę batona: \n";
		std::cin >> w;
		std::cout << "Podaj ilość kalorii batona: \n";
		std::cin >> k;
	obsluga_batona (baton, m, w, k);
	}
	return 0;
}


void obsluga_batona (Batonik & baton, const char * m, const double w, const int k){
	strncpy(baton.marka, m, 39);
	baton.marka[39] = '\0';
	baton.waga = w;
	baton.kalorie = k;

	std::cout << "\nMarka: " << baton.marka << std::endl;
	std::cout << "Waga: " << baton.waga << std::endl;
	std::cout << "Ilość kalorii: " << baton.kalorie << std::endl;
}
