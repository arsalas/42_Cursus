/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:42:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/09 20:12:47 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap() : ClapTrap("default", getInitHp(), getInitEp(), getInitAtk())
{
	std::cout << "FragTrap default construct" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name, getInitHp(), getInitEp(), getInitAtk())
{
	std::cout << "FragTrap construct" << std::endl;
}

FragTrap::FragTrap(const FragTrap &scravTrap) : ClapTrap(scravTrap.getName())
{
	std::cout << "FragTrap copy construct" << std::endl;
	_hp = scravTrap.getHp();
	_ep = scravTrap.getEp();
	_atk = scravTrap.getAtk();
}

FragTrap &FragTrap::operator=(const FragTrap &scravTrap)
{
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	_name = scravTrap.getName();
	_hp = scravTrap.getHp();
	_ep = scravTrap.getEp();
	_atk = scravTrap.getAtk();

	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destroy" << std::endl;
}

void FragTrap::hightFivesGuys()
{
	std::cout << "FragTrap " << getName() << " give me a hight five" << std::endl;
}

unsigned int FragTrap::getInitHp()
{
	return 100;
}

unsigned int FragTrap::getInitEp()
{
	return 100;
}

unsigned int FragTrap::getInitAtk()
{
	return 30;
}
