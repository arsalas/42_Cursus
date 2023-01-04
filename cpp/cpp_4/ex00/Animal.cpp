/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:25:06 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/20 19:41:16 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default construct" << std::endl;
}

Animal::Animal(std::string type) : _type(type)
{
	std::cout << "Animal construct" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destroy " << std::endl;
}

Animal::Animal(const Animal &animal) : _type(animal.getType())
{
	std::cout << "Animal copy construct" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	_type = animal.getType();

	return *this;
}

std::string Animal::getType() const
{
	return _type;
}

void Animal::makeSound() const
{
	std::cout << " " << std::endl;
}