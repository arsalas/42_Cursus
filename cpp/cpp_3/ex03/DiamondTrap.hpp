/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:16:01 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/10 12:47:07 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DiamondTrap_HPP
#define DiamondTrap_HPP

#include "iostream"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;

public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &diamondTrap);
	~DiamondTrap(void);

	DiamondTrap &operator=(const DiamondTrap &diamondTrap);

	void whoAmI();

	std::string getName() const;
};

#endif