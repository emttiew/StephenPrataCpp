#include <iostream>

void show_array(const double ar[], int n);
int fill_array(double ar[], int limit);
double average(double ar[], int n);

const int Max = 10;

int main(){
	using namespace std;
	double golf[Max];
	int size = fill_array(golf, Max);
	show_array(golf, size);
	cout << "Srednia wynikow golfowych: " << average(golf, size) << endl;


	return 0;
}

double average(double ar[], int n){
	double temp;
	int i;
	for (i = 0; i< n; i++){
		temp += ar[i];
	}
	return temp/i;

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
