#include <iostream>

const int size = 5;

template <typename T>
T max5(const T arr[]);

int main(){
	int tb1[size] = {1,8,3,4,5};
	double tb2[size] = {1.2, 1.3, 1.4, 1.5, 1.6};

	std::cout << "Największa liczba z tablicy int: " << max5(tb1) << std::endl;
	std::cout << "Największa liczba z tablicy double: " << max5(tb2) << std::endl;

	return 0;
}


template <typename T>
T max5(const T arr[]){
	T temp = arr[0];
	for (int i = 1; i < size; i++)
	{
		temp = (temp > arr[i]) ? temp : arr[i];
	}
	return temp;
}
