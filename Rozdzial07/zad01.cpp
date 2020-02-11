#include <iostream>

using namespace std;

double srednia ( double a, double b);

int main (){
	double a, b;
	cout << "Podaj zmienne a oraz b do sredniej harmonicznej:\n";
	while (cin >> a >> b && a != 0 && b != 0){
		cout << "Srednia harmoniczna: " << srednia(a, b) << endl;
		cout << "Podawaj dalej, lub wpisz 'q' lub 0 do podanych wartosci, aby zakonczyc\n";
	}
	return 0;
}

double srednia ( double a, double b){
	return 2.0 * a*b / (a + b);
}
