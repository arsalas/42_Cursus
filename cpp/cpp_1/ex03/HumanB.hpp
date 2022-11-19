/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:37:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/04 14:13:43 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanB_H
#define HumanB_H
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	std::string name;
	Weapon *weapon;

public:
	HumanB(std::string name) : name(name){};
	void attack(void);
	void setWeapon(Weapon *weapon);
};

#endif