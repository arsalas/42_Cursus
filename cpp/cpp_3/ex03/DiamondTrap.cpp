/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:42:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/10 15:16:04 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default construct " << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
{
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hp = FragTrap::getInitHp();
	_ep = ScavTrap::getInitEp();
	_atk = FragTrap::getInitAtk();
	std::cout << "DiamondTrap construct " << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap copy construct" << std::endl;
	ClapTrap::_name = diamondTrap.ClapTrap::getName();
	_name = diamondTrap.getName();
	_hp = diamondTrap.getHp();
	_ep = diamondTrap.getEp();
	_atk = diamondTrap.getAtk();
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destroy" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &diamondTrap)
{
	std::cout << "DiamondTrap copy assignment operator called" << std::endl;
	ClapTrap::_name = diamondTrap.ClapTrap::getName();
	_name = diamondTrap.getName();
	_hp = diamondTrap.getHp();
	_ep = diamondTrap.getEp();
	_atk = diamondTrap.getAtk();

	return *this;
}

std::string DiamondTrap::getName() const
{
	return _name;
}

void DiamondTrap::whoAmI()
{
	std::cout << "I'm DiamondTrap and my name is " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
