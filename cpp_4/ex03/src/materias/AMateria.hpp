/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:44:50 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/25 15:23:57 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMateria_H
#define AMateria_H

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
protected:
public:
	AMateria(std::string const &type);

	std::string const &getType() const; // Returns the materia type
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif