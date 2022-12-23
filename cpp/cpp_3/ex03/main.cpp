/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:23:50 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/22 18:10:59 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamondTrap("Arma 1");
	std::cout << "Name:\t" << diamondTrap.DiamondTrap::getName() << std::endl;
	std::cout << "Clap:\t" << diamondTrap.ClapTrap::getName() << std::endl;
	std::cout << "Hp:\t" << diamondTrap.getHp() << std::endl;
	std::cout << "Ep:\t" << diamondTrap.getEp() << std::endl;
	std::cout << "Atk:\t" << diamondTrap.getAtk() << std::endl;

	diamondTrap.whoAmI();

	diamondTrap.attack("Human");
	diamondTrap.takeDamage(9999);
	diamondTrap.beRepaired(1000);
	diamondTrap.hightFivesGuys();

	return 0;
}