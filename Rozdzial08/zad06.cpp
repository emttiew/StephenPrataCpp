#include <iostream>
#include <cstring>


template <typename T>
T maxn(T arr[], int n);

template <> const char * maxn(const char * arr[], int n);

int main(){
	int tb1[] = {1,8,3,4,5};
	double tb2[] = {1.2, 1.3, 1.4, 1.5};
	char tab3[5][20] = { {"Krótki"}, {"Krótki2"}, {"Krótki3"}, {"Najdłuższy1"}, {"Najdłuższy2"} };
	const char * arrs[5];
	for (int i = 0; i < 5; i++)
		arrs[i] = &tab3[i][0];

	const char * wsk = maxn(arrs, 5);

	std::cout << "Największa liczba z tablicy int: " << maxn(tb1, 5) << std::endl;
	std::cout << "Największa liczba z tablicy double: " << maxn(tb2, 4) << std::endl;
	std::cout << "Adres pierwszego najdłuższego napisu: " << &wsk << std::endl;
	std::cout << "Pierwszy najdłuższy napis: " << wsk << std::endl;

	return 0;
}


template <typename T>
T maxn(T arr[], int n){
	T temp = arr[0];
	for (int i = 1; i < n; i++)
	{
		temp = (temp > arr[i]) ? temp : arr[i];
	}
	return temp;
}

template <> const char * maxn(const char * arr[], int n){
	const char * temp = arr[0];
	for (int i = 0; i < n; i++)
	{
		temp = (strlen(temp) >= strlen(arr[i])) ? temp : arr[i];
	}
	return temp;
}
