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

Cat::Cat() : _brain(new Brain)
{
	_type = "Cat";
	std::cout << "Cat default construct" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destroy" << std::endl;
}

Cat::Cat(const Cat &cat)
{
	_type = cat.getType();
	std::cout << "Cat copy construct" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
	_type = cat.getType();
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "miau!" << std::endl;
}

std::string Cat::getType() const
{
	return _type;
}
