/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:37:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/04 14:00:32 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_H
#define Weapon_H
#include <iostream>

class Weapon
{
private:
	std::string type;

public:
	Weapon(std::string type) : type(type){};
	std::string &getType(void);
	void setType(std::string const &value);
};

#endif