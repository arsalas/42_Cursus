/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:16:01 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/09 13:30:25 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
#define ClapTrap_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string _name;
	unsigned int _hp;
	unsigned int _ep;
	unsigned int _atk;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap &clapTrap);
	~ClapTrap(void);

	ClapTrap &operator=(const ClapTrap &clapTrap);

	// GETTERS
	std::string getName() const;
	unsigned int getHp() const;
	unsigned int getEp() const;
	unsigned int getAtk() const;
	// SETTERS
	void setHp(unsigned int hp);
	void setEp(unsigned int ep);
	void setAtk(unsigned int atk);

	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif