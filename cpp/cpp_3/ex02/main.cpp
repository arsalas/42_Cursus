/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:23:50 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/10 12:40:36 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap fragTrap("Sword");
	std::cout << "Name:\t" << fragTrap.getName() << std::endl;
	std::cout << "Hp:\t" << fragTrap.getHp() << std::endl;
	std::cout << "Ep:\t" << fragTrap.getEp() << std::endl;
	std::cout << "Atk:\t" << fragTrap.getAtk() << std::endl;

	fragTrap.attack("Human");
	fragTrap.takeDamage(9999);
	fragTrap.beRepaired(1000);
	fragTrap.hightFivesGuys();

	return (0);
}