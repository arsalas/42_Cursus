/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:16:29 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/03 13:36:23 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << this->name  << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string zombie_name)
{
	name = zombie_name;
}

Zombie::~Zombie() 
{
	std::cout << this->name << " destroyed" << std::endl;
}
