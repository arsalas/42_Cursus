/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:37:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/04 14:08:56 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HumanA_H
#define HumanA_H
#include "iostream"
#include "Weapon.hpp"

class HumanA
{
private:
	std::string name;
	Weapon &weapon;

public:
	HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) {};
	void attack(void);
};

#endif