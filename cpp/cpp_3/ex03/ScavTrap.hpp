/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:16:01 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/10 12:41:09 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScavTrap_HPP
#define ScavTrap_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
protected:
	unsigned int getInitHp();
	unsigned int getInitEp();
	unsigned int getInitAtk();

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap &scavTrap);
	~ScavTrap(void);

	ScavTrap &operator=(const ScavTrap &scavTrap);

	void guardGate();
};

#endif