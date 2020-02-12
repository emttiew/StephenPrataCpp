#include <iostream>
#include <cstring>

struct stringy {
	char * str;
	int ct;
};

void set(stringy & st, const char test[]);
void show(const stringy & st, int n = 1);
void show(const char str[], int n = 1);

int main(){
	stringy beany;
	char testing[] = "Rzeczywistość to już nie to, co kiedyś";
	set(beany, testing);
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Gotowe!");
	delete [] beany.str;
	return 0;
}

void set(stringy & st, const char test[]){
	const int test_size = strlen(test);
	char * pt = new char[test_size];
	st.str = pt;
	strcpy(st.str, test);
	st.ct = test_size;
}

void show(const stringy & st, int n){
	using std::cout;
	using std::endl;
	if (n > 1){
		while(n)
		{
			cout << n << ". " << st.str << endl;
			n--;
		}
	} else
	cout << "Wywołanie z parametrem domyślnym: \n" << st.str << endl;
}

void show(const char str[], int n){
	using std::cout;
	using std::endl;
	if (n > 1){
			while(n)
			{
				cout << n << ". " << str << endl;
				n--;
			}
		} else
		cout << "Wywołanie z parametrem domyślnym: \n" << str << endl;
}
