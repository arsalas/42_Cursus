/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:27:50 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/20 19:41:21 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default construct" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destroy" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal()
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
