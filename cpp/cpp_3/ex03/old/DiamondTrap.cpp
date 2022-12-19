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

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
	DiamondTrap::_name = name;
	DiamondTrap::_hp = FragTrap::_hp;
	DiamondTrap::_ep = ScavTrap::_ep;
	DiamondTrap::_atk = FragTrap::_atk;
	std::cout << "DiamondTrap construct " << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destroy" << std::endl;
}

std::string DiamondTrap::getName() const
{
	return DiamondTrap::_name;
}

unsigned int DiamondTrap::getHp() const
{
	return DiamondTrap::_hp;
}

unsigned int DiamondTrap::getEp() const
{
	return DiamondTrap::_ep;
}

unsigned int DiamondTrap::getAtk() const
{
	return DiamondTrap::_atk;
}
