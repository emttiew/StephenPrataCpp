#include "sales.h"

using namespace SALES;

int main(){

	Sales s;
	double arr[3] = {1.1, 1.2, 1.8};
	setSales(s, arr, 3);
	showSales(s);
	setSales(s);
	showSales(s);

	return 0;
}
