/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:23:50 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/09 13:25:30 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap clapTrap("Arma 1");
	clapTrap.attack("humano");
	clapTrap.takeDamage(9999);
	clapTrap.beRepaired(1000);
	return (0);
}