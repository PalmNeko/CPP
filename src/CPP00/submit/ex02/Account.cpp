#include "Account.hpp"
#include <iostream>
#include <locale>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
    return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
    return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::_nbAccounts << ";";
    std::cout << "total:" << Account::_totalAmount << ";";
    std::cout << "deposits:" << Account::_totalNbDeposits << ";";
    std::cout << "withdrawals:" << Account::_totalNbWithdrawals;
    std::cout << std::endl;
    return ;
}

Account::Account( int initial_deposit )
    : _amount(initial_deposit)
{
    this->_accountIndex = Account::_nbAccounts++;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_totalAmount += this->_amount;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->checkAmount() << ";";
    std::cout << "created";
    std::cout << std::endl;
}

Account::~Account( void )
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->checkAmount() << ";";
    std::cout << "closed";
    std::cout << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    int const p_amount = this->checkAmount();

    this->_amount += deposit;
    this->_nbDeposits += 1;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits += 1;
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << p_amount << ";";
    std::cout << "deposit:" << deposit << ";";
    std::cout << "amount:" << this->checkAmount() << ";";
    std::cout << "nb_deposits:" << this->_nbDeposits;
    std::cout << std::endl;
    return ;
}

bool	Account::makeWithdrawal( int withdrawal )
{
    int const p_amount = this->checkAmount();

    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << p_amount << ";";
    if (withdrawal > this->_amount)
    {
        std::cout << "withdrawal:refused";
        std::cout << std::endl;
        return (false);
    }
    this->_amount -= withdrawal;
    this->_nbWithdrawals += 1;
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals += 1;
    std::cout << "withdrawal:" << withdrawal << ";";
    std::cout << "amount:" << this->checkAmount() << ";";
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const
{
    return (this->_amount);
}

void	Account::displayStatus( void ) const
{
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->checkAmount() << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals;
    std::cout << std::endl;
    return ;
}

/** private */

void	Account::_displayTimestamp( void )
{
    std::time_t timestamp = std::time(NULL);
    std::tm * now = std::localtime ( &timestamp );
    std::locale loc;
    const std::time_put<char>& tmput = std::use_facet<std::time_put<char> >(loc);
    std::string pattern("[%G%m%d_%H%M%S] ");
    tmput.put(std::cout, std::cout, ' ',
        now, pattern.data(), pattern.data() + pattern.length());
    return ;
}

Account::Account( void )
    : _amount(0),
    _nbDeposits(0),
    _nbWithdrawals(0)
{
    this->_accountIndex = Account::_nbAccounts++;
}
