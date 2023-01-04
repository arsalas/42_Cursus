/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:27:50 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/23 19:22:22 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : _brain(new Brain)
{
	_type = "dog";
	std::cout << "Dog default construct" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destroy" << std::endl;
}

Dog::Dog(const Dog &dog) : _brain(new Brain(*dog._brain))
{
	_type = dog.getType();
	std::cout << "Dog copy construct" << std::endl;
}

Dog &Dog::operator=(const Dog &dog)
{
	_type = dog.getType();
	*_brain = *dog._brain;
	return *this;
}

std::string Dog::getType() const
{
	return _type;
}

void Dog::makeSound() const
{
	std::cout << "guau!" << std::endl;
}

void Dog::setIdea(std::string str) const
{
	_brain->setIdea(str);
}

std::string Dog::getIdea(unsigned int position) const
{
	return _brain->getIdea(position);
};
