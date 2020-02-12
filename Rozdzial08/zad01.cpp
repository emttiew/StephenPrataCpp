#include <iostream>
#include <string>

void show_string(const std::string & s, int n = 0);


int main(){
	std::string one = "Cyka Blyat";
	show_string(one);			//1
	show_string(one, 1);		//2
	show_string(one);			//3
	show_string(one, 10);		//4
	show_string(one);			//5
	show_string(one, 100);		//6
	return 0;
}


void show_string(const std::string & s, int n)
{
	static int function_called = 1;
	if (n != 0)
	{
		for (int i = 0; i < function_called; i++)
			std::cout << ( i + 1) << ". " << s << std::endl;
	} else
		std::cout << s << std::endl;
	function_called++;
}
