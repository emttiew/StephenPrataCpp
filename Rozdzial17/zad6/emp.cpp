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
    return os;
}

abstr_emp::~abstr_emp()
{ }

void abstr_emp::writeall(std::ofstream & out_f) const
{
    out_f << fname << '\n';
    out_f << lname << '\n';
    out_f << job << '\n';
}

void abstr_emp::getall(std::ifstream & in_f) 
{
    getline(in_f, fname);
    getline(in_f, lname);
    getline(in_f, job);
}

void employee::ShowAll() const
{
    std::cout << "Pracownik: " << '\n';
    abstr_emp::ShowAll();
}

void employee::SetAll()
{
    abstr_emp::SetAll();
}

void employee::writeall(std::ofstream & out_f) const
{
    out_f << abstr_emp::Employee << '\n';
    abstr_emp::writeall(out_f);
}

void employee::getall(std::ifstream & in_f) 
{
    abstr_emp::getall(in_f);
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

void manager::writeall(std::ofstream & out_f) const
{
    out_f << abstr_emp::Manager << '\n';
    abstr_emp::writeall(out_f);
    out_f << inchargeof << '\n';
} 

void manager::getall(std::ifstream & in_f) 
{
    abstr_emp::getall(in_f);
    in_f >> inchargeof;
    in_f.get();
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

void fink::writeall(std::ofstream & out_f) const
{
    out_f << abstr_emp::Fink << '\n';
    abstr_emp::writeall(out_f);
    out_f << reportsto <<'\n';
}

void fink::getall(std::ifstream & in_f) 
{
    abstr_emp::getall(in_f);
    getline(in_f, reportsto);
}

void highfink::ShowAll() const
{
    std::cout << "Bardzo mroczny typ: " << '\n';
    abstr_emp::ShowAll();
    std::cout << "Raportuje do: " << ReportsTo() <<'\n';
    std::cout << "Liczba luczi za których mroczny typ jest odpowiedzialny: " << InChargeOf() << '\n';
}

void highfink::SetAll()
{
    abstr_emp::SetAll();
    std::cout << "Wprowadź do kogo raportuje: \n";
    getline(std::cin, ReportsTo());
    std::cout << "Podaj liczbę ludzi, za których manager jest odpowiedzialny: \n";
    std::cin >> InChargeOf();
    if (InChargeOf() < 0)
    {
        InChargeOf() = 0;
    }
}

void highfink::writeall(std::ofstream & out_f) const
{
    out_f << abstr_emp::Highfink << '\n';
    abstr_emp::writeall(out_f);
    out_f << ReportsTo() << '\n';
    out_f << InChargeOf() << '\n';
}

void highfink::getall(std::ifstream & in_f) 
{
    abstr_emp::getall(in_f);
    getline(in_f, ReportsTo());
    in_f >> InChargeOf();    
}