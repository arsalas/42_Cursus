/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:42:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/09 20:12:47 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("defaul", getInitHp(), getInitEp(), getInitAtk())
{
	std::cout << "ScavTrap default construct" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name, getInitHp(), getInitEp(), getInitAtk())
{
	std::cout << "ScavTrap construct" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap.getName())
{
	_hp = scavTrap.getHp();
	_ep = scavTrap.getEp();
	_atk = scavTrap.getAtk();
	std::cout << "ClapTrap copy construct" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	_name = scavTrap.getName();
	_hp = scavTrap.getHp();
	_ep = scavTrap.getEp();
	_atk = scavTrap.getAtk();

	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destroy" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << getName() << " have enterred in Gate keeper mode" << std::endl;
}

unsigned int ScavTrap::getInitHp()
{
	return 100;
}

unsigned int ScavTrap::getInitEp()
{
	return 50;
}

unsigned int ScavTrap::getInitAtk()
{
	return 20;
}
