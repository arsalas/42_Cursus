/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/20 19:40:57 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_H
#define WrongAnimal_H
#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	virtual ~WrongAnimal();
	WrongAnimal();
	WrongAnimal(const WrongAnimal &animal);

	WrongAnimal &operator=(const WrongAnimal &animal);

	std::string getType() const;
	virtual void makeSound() const;

protected:
	WrongAnimal(std::string type);
};

#endif