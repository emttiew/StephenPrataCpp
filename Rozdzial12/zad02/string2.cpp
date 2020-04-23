// string1.cpp -- implementacje metod klasy String
#include <cstring>    // albo string.h
#include <cctype>     // funkcje znakowe
#include "string2.h"  // włącza plik nagłówkowy <iostream>
using std::cin;
using std::cout;

// inicjalizacja statycznej składowej klasy
int String::num_strings = 0;

// metoda statyczna
int String::HowMany()
{
    return num_strings;
}

// metody klasy
String::String(const char * s)          // konstruuje obiekt String z ciągu C
{
    len = std::strlen(s);               // ustawienie długości ciągu
    str = new char[len + 1];            // przydział pamięci
    std::strcpy(str, s);                // inicjalizacja wskaźnika ciągu
    num_strings++;                      // aktualizacja licznika obiektów
    //cout << "Konstruktor char\n";
}

String::String()                        // konstruktor domyślny
{
    len = 4;
    str = new char[1];
    str[0] = '\0';                      // domyślny ciąg obiektów klasy
    num_strings++;
    //cout << "Konstruktor domyślny\n";
}

String::String(const String & st)
{
    num_strings++;                      // aktualizacja składowej statycznej
    len = st.len;                       // ta sama długość ciągu
    str = new char [len + 1];           // przydział pamięci
    std::strcpy(str, st.str);           // skopiowanie ciągu
    //cout << "Konstruktor kopiujący\n";
}

void String::stringlow() const
{
    int i = 0;
    while(str[i] != '\0')
    {
        str[i] = tolower(str[i]);
        i++;        
    }
}

void String::stringup() const
{
    int i = 0;
    while(str[i] != '\0')
    {
        str[i] = toupper(str[i]);
        i++;        
    }
}

int String::has(const char s) const
{
    int count = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        if (s == tolower(str[i]) || s == toupper(str[i]))
            count++;
        i++;
    }
    return count;
}

String::~String()                        // destruktor (niezbędny)
{
    --num_strings;                       // koniecznie
    delete [] str;                       // koniecznie
}

// metody przeciążające operatory

// dodawanie obiektów
String operator+(const String &st, const String &st2)
{
    int len_sum = st.len + st2.len;
    char * temp_str = new char [len_sum + 1];
    strcpy(temp_str, st.str);
    strcpy((temp_str + st.len), st2.str);
    String sum(temp_str);
    return sum;
}

String operator+(const char * st1, const String &st2)
{
    int len_sum = strlen(st1) + st2.len;
    char * temp_str = new char [len_sum + 1];
    strcpy(temp_str, st1);
    strcat(temp_str, st2.str);
    String sum(temp_str);
    return sum;
}

String operator+(const String &st1, const char * st2)
{
    int len_sum = strlen(st2) + st1.len;
    char * temp_str = new char [len_sum + 1];
    strcpy(temp_str, st1.str);
    strcat(temp_str, st2);
    String sum(temp_str);
    return sum;
}

// przypisywanie obiektu klasy String do innego obiektu tej klasy
String & String::operator=(const String & st)
{
    if (this == &st)
        return *this;
    delete [] str;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    return *this;
}

// przypisywanie ciągu C do obiektu klasy String
String & String::operator=(const char * s)
{
    delete [] str;
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this;
}

// pełny dostęp do znaków ciągu (dla obiektów zwykłych)
char & String::operator[](int i)
{
    return str[i];
}

// dostęp (do odczytu) do znaków ciągu (dla obiektów const)
const char & String::operator[](int i) const
{
    return str[i];
}

// zaprzyjaźnione funkcje przeciążające operatory
bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str, st2.str) == 0);
}

// wyprowadzenie ciągu na wyjście
ostream & operator<<(ostream & os, const String & st)
{
    os << st.str;
    return os;
}

// wczytywanie ciągu z wejścia (uproszczone)
istream & operator>>(istream & is, String & st)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

