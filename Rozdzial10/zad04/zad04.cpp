#include "sales2.h"

using namespace SALES;

int main(){
    double arr[3] = {1.1, 1.2, 1.8};
    Sales sale;
    Sales sale2(arr, 3);
    sale.showSales();
    sale2.showSales();
    return 0;
}