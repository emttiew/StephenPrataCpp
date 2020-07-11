#include "emp.h"

void abstr_emp::ShowAll() const
{
    std::cout << "Imię: " << fname << '\n';
    std::cout << "Nazwisko: " << lname << '\n';
    std::cout << "Praca: " << job << '\n';
}

void abstr_emp::SetAll()
{
    std::cout << "Podaj imię: ";
	std::cin >> fname;
	while (std::cin.get() != '\n')
		continue;
	std::cout << "Podaj nazwisko: ";
	std::cin >> lname;
	while (std::cin.get() != '\n')
		continue;
	std::cout << "Podaj nazwę stanowiska: ";
	getline(std::cin, job);
}

std::ostream & operator<<(std::ostream & os, const abstr_emp & e)
{
    os << "Imię: " << e.fname << '\n';
    os << "Nazwisko: " << e.lname << '\n';
    os << "Praca: " << e.job << '\n';
    return os;
}

abstr_emp::~abstr_emp()
{ }

void employee::ShowAll() const
{
    std::cout << "Pracownik: " << '\n';
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

void manager::ShowAll() const
{
    std::cout << "Manager: " << '\n';
    abstr_emp::ShowAll();
    std::cout << "Liczba luczi za których manager jest odpowiedzialny: " << inchargeof << '\n';
}

void manager::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Podaj liczbę ludzi, za których manager jest odpowiedzialny: \n";
    std::cin >> inchargeof;
    if (inchargeof < 0)
    {
        inchargeof = 0;
    }
}

void fink::ShowAll() const
{
    std::cout << "Mroczny typ: " << '\n';
    abstr_emp::ShowAll();
    std::cout << "Raportuje do: " << reportsto <<'\n';
    
}

void fink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Wprowadź do kogo raportuje: \n";
    getline(std::cin, reportsto);
}

void highfink::ShowAll() const
{
    std::cout << "Bardzo mroczny typ: " << '\n';
    abstr_emp::ShowAll();
    std::cout << "Raportuje do: " << fink::ReportsTo() <<'\n';
    std::cout << "Liczba luczi za których mroczny typ jest odpowiedzialny: " << manager::InChargeOf() << '\n';
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Wprowadź do kogo raportuje: \n";
    getline(std::cin, fink::ReportsTo());
    std::cout << "Podaj liczbę ludzi, za których manager jest odpowiedzialny: \n";
    std::cin >> manager::InChargeOf();
    if (manager::InChargeOf() < 0)
    {
        manager::InChargeOf() = 0;
    }
}