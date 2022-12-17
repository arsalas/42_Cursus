/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:52:21 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 21:32:35 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	_point = 0;
	std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(Fixed &cpy)
{
	_point = cpy.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &cpy)
{
	_point = cpy.getRawBits();
	std::cout << "Asignation operator called" << std::endl;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _point;
}
void Fixed::setRawBits(int const raw)
{
	_point = raw;
	std::cout << "setRawBits member function called" << std::endl;
}
