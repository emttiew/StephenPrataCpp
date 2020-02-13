#include <iostream>
#include <new>
#include <cstring>

struct chaff
{
	char dross[20];
	int slag;
	chaff() {
		std::cout << "Konstruktor wywołany: [" << this << "] \n";
	}
};

const int Size = 2; // rozmiar tablicy
//const int Buf = 512; // rozmar statycznego bufora
chaff * buffer = new chaff[Size];
//char buffer[Buf];


void set_value(chaff &, const char *, const int);

void show_chaff(const chaff &);

int main(){
	chaff * p1 = new (buffer) chaff[Size];

	const char str1[] = "TEST1";
	const char str2[] = "TEST2";
	const int sl1 = 50;
	const int sl2 = 10;

	set_value(p1[0], str1, sl1);
	set_value(p1[1], str2, sl2);


	for (int i = 0; i < Size; i++){
		std::cout << (i+1) << ". \n";
		show_chaff(p1[i]);
	}

	delete buffer; // jeśli buffer jest statyczny to wykomentować
	return 0;
}


void set_value(chaff & c,const char * str, const int sl){
	strcpy(c.dross, str);
	c.slag = sl;
}


void show_chaff(const chaff & c){
	std::cout << "Dross: " << c.dross << std::endl;
	std::cout << "Slag: " << c.slag << std::endl;

}
