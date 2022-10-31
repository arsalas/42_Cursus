/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:23:50 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/10 12:40:58 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scavTrap("Arma 1");
	std::cout << "Name:\t" << scavTrap.getName() << std::endl;
	std::cout << "Hp:\t" << scavTrap.getHp() << std::endl;
	std::cout << "Ep:\t" << scavTrap.getEp() << std::endl;
	std::cout << "Atk:\t" << scavTrap.getAtk() << std::endl;

	return (0);
}