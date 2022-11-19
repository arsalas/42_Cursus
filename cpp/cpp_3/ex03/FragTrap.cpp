/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:42:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/10 12:29:22 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScravTrap construct" << std::endl;
	setHp(100);
	setEp(100);
	setAtk(30);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destroy" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High fives" << std::endl;
}
