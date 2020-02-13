#include "bank.h"
#include <iostream>


Bank::Bank(const std::string & name, const std::string & account_nr, double balance)
{
	m_name = name;
	m_account_nr = account_nr;
	m_balance = balance;
}

Bank::~Bank()
{

}

void Bank::show_data() const
{
	std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
	std::streamsize prec = std::cout.precision(2);
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Account number: " << m_account_nr << std::endl;
	std::cout << "Balance: " << m_balance << std::endl;
	std::cout.setf(orig, std::ios_base::floatfield);
	std::cout.precision(prec);

}

void Bank::deposit(const double amount)
{
	std::cout << "Deposited: " << amount << std::endl;
	m_balance += amount;
	std::cout << "Current balance: " << m_balance << std::endl;
}

void Bank::withdraw(const double amount)
{
	std::cout << "Withdrawn: " << amount << std::endl;
	m_balance -= amount;
	std::cout << "Current balance: " << m_balance << std::endl;
}
