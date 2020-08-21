#include <iostream>


int main()
{
    using std::cout;
    using std::cin;

    char ch;
    int count = 0;
    cout << "Wprowadź łańcuch znaków (wprowadzanie kończy znak '$'): \n";
    cin.get(ch);
    while(ch != '$')
    {
        cin.get(ch);
        count++;
    }        
    cout << "Ilość znaków: " << count << "\nNastępny znak wejściowy to: " << ch << std::endl;    

    return 0;
}