/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:27:50 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/23 19:14:54 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default construct" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destroy" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal()
{
	_type = dog.getType();
}

Dog &Dog::operator=(const Dog &dog)
{
	_type = dog.getType();
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "guau!" << std::endl;
}
