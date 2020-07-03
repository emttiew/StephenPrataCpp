#include "port.h"
#include <cstring>

Port::Port(const char * br, const char * st, int b) 
{
    if(!(std::strlen(st) > 20))
        std::strcpy(style, st);
    brand = new char [std::strlen(br) + 1];
    std::strcpy(brand, br);
    bottles = b;
}

Port::Port(const Port & p)
{
    std::strcpy(style, p.style);
    bottles = p.bottles;
    brand = new char [std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
}

Port & Port::operator=(const Port & p)
{
    if(this == &p)
        return *this;
    bottles = p.bottles;
    std::strcpy(style, p.style);
    delete [] brand;
    brand = new char [std::strlen(p.brand) + 1];
    std::strcpy(brand, p.brand);
    return *this;
}

Port & Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b)
{
    bottles -= b;
    return *this;
}

void Port::Show() const
{
    std::cout << "Marka: " << brand << "\n";
    std::cout << "Rodzaj: " << style << "\n";
    std::cout << "Butelek: " << bottles << "\n";
}

std::ostream & operator<<(std::ostream & os, const Port & p)
{
    os << "Marka: " << p.brand << "\n";
    os << "Rodzaj: " << p.style << "\n";
    os << "Butelek: " << p.bottles << "\n";
}

VintagePort::VintagePort() : Port()
{
    year = 0;
    nickname = new char [5];
    std::strcpy(nickname, "brak");
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br, "najlepszy rocznik", b)
{
    year = y;
    nickname = new char [std::strlen(nn) + 1];
    std::strcpy(nickname, nn);
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp)
{
    year = vp.year;
    nickname = new char [std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
}

VintagePort & VintagePort::operator=(const VintagePort & vp)
{
    if(this == &vp)
        return *this;
    Port::operator=(vp);
    delete [] nickname;
    year = vp.year;
    nickname = new char [std::strlen(vp.nickname) + 1];
    std::strcpy(nickname, vp.nickname);
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    std::cout << "Rocznik: " << year << "\n";
    std::cout << "Nickname: " << nickname << "\n";
}

std::ostream & operator<<(std::ostream & os, const VintagePort & vp)
{
    os << dynamic_cast<const Port &>(vp);
    os << "Rocznik: " << vp.year << "\n";
    os << "Nickname: " << vp.nickname << "\n";
}