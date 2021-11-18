/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bigo </var/spool/mail/bigo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:56:02 by bigo              #+#    #+#             */
/*   Updated: 2021/11/18 00:57:19 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>

static int _nbAccounts = 0;
static int	_totalAmount = 0;
static int	_totalNbDeposits = 0;
static int	_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

static int	getTotalAmount( void )
{
	return (_totalAmount);
}

static int	getNbDeposits( void )
{
	return (_totalNbDeposits);
}
static int	getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}
//[19920104_091532] index:0;amount:42;created
//[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
static void	displayAccountsInfos( void )
{
	std::cout << "accounts:" << getNbAccounts() << ';';
	std::cout << "total:" << _totalAmount << ';';
	std::cout << "deposits:" << _totalNbDeposits << ';';
	std::cout << "withdrawal:" << _totalNbWithdrawals << std::endl;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = _nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< "created" << std::endl;
}

Account::~Account( void )
{
	_nbAccounts--;
}

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	++this->_nbDeposits;
	++_totalNbDeposits;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal < this->_amount)
		return (false);
	this->_amount -= withdrawal;
	++this->_nbWithdrawals;
	++_totalNbWithdrawals;
	_totalNbWithdrawals -= withdrawal;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount
		<< ";deposits:" << this->_nbDeposits << ";withdrawals:"
		<< this->_nbWithdrawals << std::endl;
}

static void	_displayTimestamp( void )
{

}
