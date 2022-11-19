/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:42:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/10 12:56:44 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScravTrap construct" << std::endl;
	ScavTrap::setHp(100);
	ScavTrap::setEp(50);
	ScavTrap::setAtk(20);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScravTrap destroy" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScravTrap have enterred in Gate keeper mode" << std::endl;
}
