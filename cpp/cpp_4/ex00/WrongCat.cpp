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

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("Wrong Cat")
{
	std::cout << "WrongCat default construct" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destroy" << std::endl;
}

WrongCat::WrongCat(const WrongCat &cat) : WrongAnimal(cat.getType())
{
	std::cout << "WrongCat copy construct" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &cat)
{
	_type = cat.getType();
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "wrong miauuuu!" << std::endl;
}
