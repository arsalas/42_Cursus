/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:16:29 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/03 16:09:46 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name  << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(std::string zombie_name)
{
	this->name = zombie_name;
}

Zombie::~Zombie() 
{
	std::cout << this->name << " destroyed" << std::endl;
}
