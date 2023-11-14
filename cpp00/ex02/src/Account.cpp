
#include <iostream>
#include "Account.hpp"

Account::Account(int initial_deposit)
{
	std::cout << "\033[0;32mAccount Object Created\033[0m" << std::endl;
}

Account::~Account(void)
{
	std::cout << "\033[0;31mAccount Object Destroyed\033[0m" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return(_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return(_totalAmount);
}

int Account::getNbDeposits(void)
{
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return(_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	std::cout << "accounts:" << getNbAccounts();
	std::cout << "total:" << getTotalAmount();
	std::cout << "deposits:" << getNbDeposits();
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	;
}

int	Account::checkAmount(void) const
{
	;
}

void	Account::displayStatus(void) const
{
	std::cout << "index:" << _accountIndex;
	std::cout << "total:" << _amount;
	std::cout << "deposits:" << _nbDeposits;
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

static void	displayTimestamp(void)
{
	;
}
