/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:16:25 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/09 13:30:50 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name(""), _hp(10), _ep(10), _atk(0)
{
	std::cout << "ClapTrap default construct" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10), _atk(0)
{
	std::cout << "ClapTrap construct" << std::endl;
}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int atk) : _name(name), _hp(hp), _ep(ep), _atk(atk)
{
	std::cout << "ClapTrap params construct" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) : _name(clapTrap.getName()), _hp(clapTrap.getHp()), _ep(clapTrap.getEp()), _atk(clapTrap.getAtk())
{
	std::cout << "ClapTrap copy construct" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destroy" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	_name = clapTrap.getName();
	_hp = clapTrap.getHp();
	_ep = clapTrap.getEp();
	_atk = clapTrap.getAtk();

	return *this;
}

std::string ClapTrap::getName() const
{
	return (_name);
}

unsigned int ClapTrap::getHp() const
{
	return (_hp);
}

unsigned int ClapTrap::getEp() const
{
	return (_ep);
}

unsigned int ClapTrap::getAtk() const
{
	return (_atk);
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
	std::cout << "ClapTrap " << _name << " attack " << target << ", causing " << _atk << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int damage = amount < _hp ? _hp - amount : _hp;
	_hp -= damage;
	std::cout << "ClapTrap " << _name << " take " << damage << " points of damage!" << std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	int repaired = _ep > amount ? amount : _ep;
	_hp += repaired;
	_ep -= amount;
	std::cout << "ClapTrap " << _name << " repaired " << repaired << " points of damage!" << std::endl;
}
