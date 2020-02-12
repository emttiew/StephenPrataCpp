// tempover.cpp -- przeciążanie szablonów
#include <iostream>

template <typename T>            // szablon A
void ShowArray(T arr[], int n);

template <typename T>            // szablon B
void ShowArray(T * arr[], int n);

template <typename T>            // szablon C
T SumArray(T arr[], int n);

template <typename T>            // szablon D
T SumArray(T * arr[], int n);

struct debts
{
    char name[50];
    double amount;
};

int main()
{
    using namespace std;
    int things[6] = {13, 31, 103, 301, 310, 130};
    struct debts mr_E[3] =
    {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe", 1300.0},
        {"Iby Stout", 1800.0}
    };
    double * pd[3];

// ustawienie wskaźników na pola amount struktur z tablicy Mr_E
    for (int i = 0; i < 3; i++)
        pd[i] = &mr_E[i].amount;

    cout << "Wyliczanie rzeczy pana E.:\n";
// things to tablica int
    ShowArray(things, 6);  // używamy szablonu A
	cout << "Suma rzeczy pana E: " << SumArray(things, 6) << endl;
    cout << "Wyliczanie długów pana E:\n";
// pd to tablica wskaźników na double
    ShowArray(pd, 3);      // używa szablonu B (bardziej wyspecjalizowanego)
    cout << "Suma długów pana E: " << SumArray(pd, 3) << endl;
    return 0;
}

template <typename T>
void ShowArray(T arr[], int n)
{
    using namespace std;
    cout << "szablon A\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << endl;
}

template <typename T>
void ShowArray(T * arr[], int n)
{
    using namespace std;
    cout << "szablon B\n";
    for (int i = 0; i < n; i++)
        cout << *arr[i] << ' ';
    cout << endl;
}

template <typename T>
T SumArray(T arr[], int n){
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum;
}

template <typename T>
T SumArray(T * arr[], int n){
	T sum = 0;
	for (int i = 0; i < n; i++)
		sum += *arr[i];
	return sum;
}
