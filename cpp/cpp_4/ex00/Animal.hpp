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

#ifndef Animal_H
#define Animal_H
#include <iostream>

class Animal
{
protected:
	std::string _type;

public:
	virtual ~Animal();
	Animal();
	Animal(const Animal &animal);

	Animal &operator=(const Animal &animal);

	std::string getType() const;
	virtual void makeSound() const;

protected:
	Animal(std::string type);
};

#endif