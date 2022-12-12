/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:37:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 17:08:31 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Weapon_H
#define Weapon_H
#include <iostream>

class Weapon
{
private:
	std::string _type;

public:
	Weapon(std::string type) : _type(type){};
	std::string &getType(void);
	void setType(std::string const &value);
};

#endif