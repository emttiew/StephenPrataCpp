#include "bank.h"


int main(){
	Bank bank("Zbyszek", "1205091826", 907987349);
	bank.show_data();
	bank.deposit(1000000);
	bank.withdraw(500000000);
	bank.show_data();
	return 0;
}
