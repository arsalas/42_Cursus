/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:16:25 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/10 12:37:38 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap construct" << std::endl;
	_name = name;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destroy" << std::endl;
}

unsigned int ClapTrap::getHp(void)
{
	return (_hp);
}

unsigned int ClapTrap::getEp(void)
{
	return (_ep);
}

unsigned int ClapTrap::getAtk(void)
{
	return (_atk);
}

std::string ClapTrap::getName(void)
{
	return (_name);
}

void ClapTrap::setHp(unsigned int hp)
{
	_hp = hp;
}
void ClapTrap::setEp(unsigned int ep)
{
	_ep = ep;
}
void ClapTrap::setAtk(unsigned int atk)
{
	_atk = atk;
}

void ClapTrap::attack(std::string const &target)
{
	std::cout << "ClapTrap " << _name << " attack " << target << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " causing " << amount << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " repaired " << amount << " points of damage!" << std::endl;
}
