#include <iostream>

double add (double x, double y);

double multiply (double x, double y);

double divide (double x, double y);

double calculate (double x, double y, double (*pf)(double, double));



int main(){
	double a, b;
	double (*pf[3])(double, double) = {add, multiply, divide};
	while(std::cin){
	std::cout << "Podaj dwie liczby:\n";
	std::cin >> a >> b;
	if(std::cin){
		for (int i = 0; i < 3; i++){
			std::cout << "Po wywołaniu funkcji nr: " << (i + 1) << std::endl;
			std::cout << (*pf[i])(a, b) << std::endl;
		}
	}else
		std::cout << "Podano niepoprawne dane.\nProgram zostanie zakończony\n";
	}
	return 0;
}

double add (double x, double y){
	return x + y;
}

double multiply (double x, double y){
	return x * y;
}

double divide (double x, double y){
	return x / y;
}

double calculate (double x, double y, double (*pf)(double, double)){
	return (*pf)(x, y);
}


