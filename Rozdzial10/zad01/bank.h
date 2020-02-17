#include <string>

#ifndef BANK_H_
# define BANK_H_

class Bank
{
	std::string m_name, m_account_nr;
	double m_balance;
public:
	Bank(const std::string & name = "NONE", const std::string & account_nr = "NONE", double balance = 0.0);
	~Bank();
	void show_data() const;
	void deposit(const double amount);
	void withdraw(const double amount);
};


#endif
