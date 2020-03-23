// stonewt.cpp -- implementacje metod klasy Stonewt
#include <iostream>
using std::cout;
#include "stonewt.h"

// konstruuje obiekt Stonewt z wartości typu double
Stonewt::Stonewt(double lbs, Mode form)
{
    stone = int (lbs) / Lbs_per_stn; // dzielenie całkowite
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;

    if (form == STONE || form == PDS_INT || form == PDS_DOUBLE)
        mode = form;
    else
    {
        cout << "Niepoprawny trzeci argument (forma wyświetlania)\n";
        cout << "STONE - kamienie\nPDS_INT - funty\nPDS_DOUBLE - funty z częścią całkowitą\n";
        cout << "Domyślna wartość = STONE\n";
        mode = STONE;
    }
    
}       

// konstruuje obiekt Stonewt z liczby kamieni i funtów
Stonewt::Stonewt(int stn, double lbs, Mode form)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn +lbs;

    if (form == STONE || form == PDS_INT || form == PDS_DOUBLE)
        mode = form;
    else
    {
        cout << "Niepoprawny trzeci argument (forma wyświetlania)\n";
        cout << "STONE - kamienie\nPDS_INT - funty\nPDS_DOUBLE - funty z częścią całkowitą\n";
        cout << "Domyślna wartość = STONE\n";
        mode = STONE;
    }
}

Stonewt::Stonewt() // konstruktor domyślny, zeruje obiekt
{
    stone = pounds = pds_left = 0;
    mode = STONE;
}

Stonewt::~Stonewt() // destruktor
{
}

void Stonewt::set_mode(Mode form)
{
    if (form == STONE || form == PDS_INT || form == PDS_DOUBLE)
        mode = form;
    else
    {
        cout << "Niepoprawny trzeci argument (forma wyświetlania)\n";
        cout << "STONE - kamienie\nPDS_INT - funty\nPDS_DOUBLE - funty z częścią całkowitą\n";
        cout << "Domyślna wartość = STONE\n";
        mode = STONE;
    }
}

Stonewt operator+(const Stonewt & s1, const Stonewt & s2)
{
    return Stonewt(s1.pounds+s2.pounds);
}

Stonewt operator-(const Stonewt & s1, const Stonewt & s2)
{
    return Stonewt(s1.pounds-s2.pounds);
}

Stonewt operator*(const Stonewt s1, const Stonewt & s2)
{
    return (s1.pounds * s2.pounds);
}

Stonewt operator*(const Stonewt & s, double d)
{
    return (s.pounds*d);
}

Stonewt operator*(double d, const Stonewt & s)
{
    return (s.pounds*d);
}

bool operator>(const Stonewt & s1, const Stonewt & s2)
{
    if (s1.pounds > s2.pounds)
        return true;
    else 
        return false;
}

bool operator<(const Stonewt & s1, const Stonewt & s2)
{
    if (s1.pounds < s2.pounds)
        return true;
    else 
        return false;
}

bool operator==(const Stonewt & s1, const Stonewt & s2)
{
    if (s1.pounds == s2.pounds)
        return true;
    else 
        return false;
}

bool operator>=(const Stonewt & s1, const Stonewt & s2)
{
    if (s1.pounds >= s2.pounds)
        return true;
    else 
        return false;
}

bool operator<=(const Stonewt & s1, const Stonewt & s2)
{
    if (s1.pounds <= s2.pounds)
        return true;
    else 
        return false;
}

bool operator!=(const Stonewt & s1, const Stonewt & s2)
{
    if (s1.pounds != s2.pounds)
        return true;
    else 
        return false;
}

std::ostream & operator<<(std::ostream & os, const Stonewt & st)
{
    if (st.mode == Stonewt::STONE)
        os << st.stone << " kamieni, " << st.pds_left << " funtów\n";
    else if (st.mode == Stonewt::PDS_INT)
        os << (int)st.pounds << " funtów\n";
    else if (st.mode == Stonewt::PDS_DOUBLE)
        os << st.pounds << " funtów\n";
    else 
        os << "Niepoprawny tryb reprezentacji obiektu Stonewt\n";
    return os;
}
