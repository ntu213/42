
#include <iostream>
#include <ctime>
#include <iomanip>

#include "Account.hpp"


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account()
{
	_displayTimestamp();
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created\n";
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_totalAmount += initial_deposit;
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed\n";
}


void	Account::_displayTimestamp()
{
	std::time_t	res = std::time(nullptr);
	std::cout << std::setfill('0') << "["
		<< std::setw(4) << std::localtime(&res)->tm_year + 1900
		<< std::setw(2) << std::localtime(&res)->tm_mon + 1
		<< std::setw(2) << std::localtime(&res)->tm_mday
		<< "_"
		<< std::setw(2) << std::localtime(&res)->tm_hour
		<< std::setw(2) << std::localtime(&res)->tm_min
		<< std::setw(2) << std::localtime(&res)->tm_sec
		<< "] ";
}

int Account::getNbAccounts()
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount()
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits()
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (Account::_totalNbWithdrawals);
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout
		<< "accounts:" << Account::_nbAccounts << ";"
		<< "total:" << Account::_totalAmount << ";"
		<< "deposits:" << Account::_totalNbDeposits << ";"
		<< "withdrawals:" << Account::_totalNbWithdrawals << ";\n";
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << ";\n";
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "depiosit:" << deposit << ";"
		<< "amount:" << this->_amount + deposit << ";"
		<< "nb_deposits:" << this->_nbDeposits + 1 << ";\n";
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";"
		<< "withdrawal:";
	if (withdrawal > this->_amount)
	{
		std::cout << "refused\n";
		return (0);
	}
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout << withdrawal
		<< "amount:" << this->_amount << ";"
		<< "nd_withdrawals:" << this->_nbWithdrawals << ";\n";
	return (1);
}

int	Account::checkAmount() const
{
	return (this->_amount);
}
