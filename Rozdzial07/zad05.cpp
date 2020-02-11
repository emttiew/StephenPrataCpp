#include <iostream>

int factorial(int n);

int main(){
	using namespace std;
	int n;
	cout << "Podaj wartość do obliczenia silni: \n";
	while (cin >> n){
		cout << "Silnia wynosi: " << factorial(n) << endl;
		cout << "Wpisz kolejną wartość, lub 'q', aby zakończyć.\n";
	}
	return 0;
}

int factorial(int n){
	if (n == 0 || n == 1)
		return 1;
	else if (n > 0){
		n *= factorial(n - 1);
	}
		return n;
}
