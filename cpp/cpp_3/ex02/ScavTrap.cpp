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

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default construct" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap construct" << std::endl;
	_hp = 100;
	_ep = 50;
	_atk = 20;
}

ScavTrap::ScavTrap(const ScavTrap &scavTrap) : ClapTrap(scavTrap.getName())
{
	std::cout << "ClapTrap copy construct" << std::endl;
	_hp = scavTrap.getHp();
	_ep = scavTrap.getEp();
	_atk = scavTrap.getAtk();
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
