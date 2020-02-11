#include <iostream>

void show_array(const double ar[], int n);
int fill_array(double ar[], int limit);
void reverse(double ar[], int n);

const int Max = 10;

int main(){
	using namespace std;
	double tab[Max];
	int size = fill_array(tab, Max);
	show_array(tab, size);
	cout << "Odwrócona tablica:\n";
	reverse(tab, size);
	show_array(tab, size);

	return 0;
}

void reverse(double ar[], int n){
	double temp;
	int i;
	for (i = 0; i< n; i++, n--){
		temp = ar[i];
		ar[i] = ar[n-1];
		ar[n-1] = temp;
	}

}


void show_array(const double ar[], int n){
	using namespace std;
	for (int i = 0; i < n; i++){
		cout << "Wynik nr " << (i + 1) << ": ";
		cout << ar[i] << endl;
	}

}

int fill_array(double ar[], int limit){
	using namespace std;
	double temp;
	int i;
	cout << "Podaj 10 wartości do tablicy\n";
	for (i = 0; i < limit; i++){
		cout << "Podaj wartosc nr " << (i + 1) << ": \n";
		cin >> temp;
		if(!cin){
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bledne dane, wprawadzanie przerwane.\n";
			break;
		}
		else if (temp < 0)
			break;
		ar[i] = temp;
	}
	return i;
}
