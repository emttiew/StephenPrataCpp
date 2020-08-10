#include <iostream>
#include <cctype>
#include <algorithm>

bool isPalindrome(std::string & s);

int main() 
{
    std::string palindrome;
          
    std::cout << "Podaj palindrom: \n";
    getline(std::cin, palindrome);
    if (isPalindrome(palindrome))    
        std::cout << "Zgadza się. To jest palindrom.\n";
    else
        std::cout << "Błąd. Podany wyraz nie jest palindromem.\n";
        
    return 0;
}

bool isPalindrome(std::string & s)
{
    std::transform(s.begin(), s.end(), s.begin(), 
        [](unsigned char c){ return std::tolower(c); });
    s.erase(remove_if(s.begin(), s.end(), isspace), s.end());
    std::string::iterator it;
    std::string::reverse_iterator rit;
    for(it = s.begin(), rit = s.rbegin(); it != s.end(); ++it, ++rit)
    {
        if(*it != *rit)
            return false;
    }
    return true;
}