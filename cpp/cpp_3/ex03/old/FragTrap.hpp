/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:16:01 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/10 12:41:09 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FragTrap_HPP
#define FragTrap_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:
public:
	FragTrap(std::string name);
	FragTrap(const FragTrap &fragTrap);
	~FragTrap(void);

	FragTrap &operator=(const FragTrap &fragTrap);

	void hightFivesGuys();

protected:
	FragTrap();
};

#endif