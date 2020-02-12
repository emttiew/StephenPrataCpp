#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

void capslock(std::string & s );

int main(){
	using std::cout;
	using std::cin;
	using std::endl;

	std::string s1;
	cout << "Podaj łańcuch (q, aby skończyć): \n";
	while (cin >> s1 && s1 != "q"){
		capslock(s1);
		cout << "Łańcuch powiększony: " << s1 << endl;
		cout << "Następny łańcuch: \n";
	}

}


void capslock(std::string & s ){
	std::for_each(s.begin(), s.end(), [](char & c){
		c = ::toupper(c);
	});
}
