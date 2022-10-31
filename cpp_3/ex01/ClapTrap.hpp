/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:16:01 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/10 12:41:34 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ClapTrap_HPP
# define ClapTrap_HPP

# include "iostream"

class ClapTrap
{
private:
	std::string _name;
	unsigned int _hp;
	unsigned int _ep;
	unsigned int _atk;

public:
	ClapTrap(std::string name);
	~ClapTrap(void);

	void setHp(unsigned int hp);
	void setEp(unsigned int ep);
	void setAtk(unsigned int atk);
	std::string getName(void);
	unsigned int getHp(void);
	unsigned int getEp(void);
	unsigned int getAtk(void);
	
	void attack(std::string const &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif