/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:27:50 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/23 19:22:42 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), _brain(new Brain)
{
	std::cout << "Cat default construct" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destroy" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal(cat.getType()), _brain(new Brain(*cat._brain))
{
	std::cout << "Cat copy construct" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	_type = cat.getType();
	*_brain = *cat._brain;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "miau!" << std::endl;
}


void Cat::setIdea(std::string str) const
{
	_brain->setIdea(str);
}

std::string Cat::getIdea(unsigned int position) const
{
	return _brain->getIdea(position);
};

