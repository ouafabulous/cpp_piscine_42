#include <string>
#include <iostream>
#include <ctime>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

Account::Account(void)
{
	return;
}

void	opti_cout(int id, int p_amount, int amount, int deposit, int withdrawal_nbdeposit, int extra, int option)
{
	if (option == 1) {
		std::cout << "index:" << id << ";amount:" << amount << ";deposits:" << deposit << ";withdrawals:" << withdrawal_nbdeposit << std::endl;
	}
	else if (option == 2) {
		std::cout << "index:" << id << ";p_amount:" << p_amount << ";deposit:" << deposit << ";amount:" << amount << ";nb_deposits:" << withdrawal_nbdeposit << std::endl;
	}
	else if (option == 3) {
		if (amount < 0) {
			std::cout << "index:" << id << ";p_amount:" << p_amount << ";withdrawal:" << "refused" << std::endl;
		}
		else {
			std::cout << "index:" << id << ";p_amount:" << p_amount << ";withdrawal:" << withdrawal_nbdeposit << ";amount:" << amount << ";nb_withdrawals:" << extra << std::endl;
		}
	}
}

void	Account::_displayTimestamp(void)
{
	char	buff[100];
	time_t	time;

	time = std::time(0);
    if (strftime(buff, sizeof buff, "[%G%m%d_%H%M%S]", std::localtime(&time))) {
		std::cout << buff << " ";
	}

}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	p_amount = this->_amount;
	this->_amount += deposit;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	opti_cout(this->_accountIndex, p_amount, this->_amount, deposit, this->_nbDeposits, 0, 2);
}

bool	Account::makeWithdrawal(int withdrawal)
{
	int	p_amount;

	p_amount = this->_amount;
	if (this->_amount - withdrawal < 0)
	{
		Account::_displayTimestamp();
		opti_cout(this->_accountIndex, p_amount, -1, this->_amount, withdrawal,this->_nbWithdrawals, 3);
		return (false);
	}
	else {
		this->_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		Account::_displayTimestamp();
		opti_cout(this->_accountIndex, p_amount, this->_amount, 0, withdrawal,this->_nbWithdrawals, 3);
		return (true);
	}
}

Account::Account(int initial_deposit) : _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	this->_accountIndex = _nbAccounts;
	Account::_nbAccounts++;
	this->_amount += initial_deposit;
	Account::_totalAmount += initial_deposit;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
	return;
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	return;
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	opti_cout(this->_accountIndex, 0, this->_amount, this->_nbDeposits, this->_nbWithdrawals, 0, 1);
}
