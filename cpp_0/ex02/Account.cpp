/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 18:24:45 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/18 18:36:51 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

Account::Account( int initial_deposit )
{
	//TODO
	this->_nbDeposits = initial_deposit
}

Account::~Account( void )
{
	//TODO
}

static int	Account::getNbAccounts( void )
{
	return this->_nbAccounts;
}

static int	Account::getTotalAmount( void )
{
	return this->_totalAmount;
}

static int	Account::getNbDeposits( void )
{
	return this->_totalNbDeposits;
}

static int	Account::getNbWithdrawals( void )
{
	return this->_totalNbWithdrawals;
}

static void	Account::displayAccountsInfos( void )
{
	//TODO
}


	void	Account::makeDeposit( int deposit ){
		//TODO
	}
	bool	Account::makeWithdrawal( int withdrawal ){
	//TODO	
	}
	int		Account::checkAmount( void ) const{
		
	}
	void	Account::displayStatus( void ) const{
		//TODO
	}

	static void	Account::_displayTimestamp( void )
	{
		//TODO
	}
