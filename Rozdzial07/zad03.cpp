#include <iostream>

using namespace std;

struct pudlo
{
    char producent[40];
    float wysokosc;
    float szerokosc;
    float dlugosc;
    float objetosc;
};

void show_struct(pudlo pudlo);
void volume(pudlo *pudlo);

int main()
{
    pudlo box = {"Nokia",10,10,20};
    cout << "Pudlo: \n";
    show_struct(box);
    volume(&box);
    cout << "Jego objetosc wynosi: " << box.objetosc << endl;
    return 0;
}

void show_struct(pudlo pudlo)
{
    cout << "Producent: " << pudlo.producent << endl;
    cout << "Wysokosc: " << pudlo.wysokosc << endl;
    cout << "Szerokosc: " << pudlo.szerokosc << endl;
    cout << "Dlugosc: " << pudlo.dlugosc << endl;
    cout << "Objetosc: " << pudlo.objetosc << endl;
}

void volume(pudlo *pudlo)
{
	pudlo->objetosc = (pudlo->dlugosc)*(pudlo->szerokosc)*(pudlo->wysokosc);
   cout << endl;
}
