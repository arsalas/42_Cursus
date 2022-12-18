/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:52:21 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 21:36:51 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	_value = 0;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;
	_value = value << _bits;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(value * (1 << _bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	_value = fixed.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Asignation operator called" << std::endl;
	_value = fixed.getRawBits();
	return *this;
}

Fixed Fixed::operator+(const Fixed &fixed) const
{
	Fixed newFixed;
	newFixed.setRawBits(_value + fixed.getRawBits());
	return newFixed;
}

Fixed Fixed::operator-(const Fixed &fixed) const
{
	Fixed newFixed;
	newFixed.setRawBits(_value - fixed.getRawBits());
	return newFixed;
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	Fixed newFixed;
	newFixed.setRawBits((_value * fixed.getRawBits()) >> _bits);
	return newFixed;
}

Fixed Fixed::operator/(const Fixed &fixed) const
{
	Fixed newFixed;
	newFixed.setRawBits((_value << _bits) / fixed.getRawBits());
	return newFixed;
}

Fixed Fixed::operator++()
{
	_value++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed newFixed(*this);
	operator++();
	return newFixed;
}

Fixed Fixed::operator--()
{
	_value--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed newFixed(*this);
	operator--();
	return (newFixed);
}

bool Fixed::operator>(const Fixed &fixed) const
{
	return _value > fixed.getRawBits();
}
bool Fixed::operator<(const Fixed &fixed) const
{
	return _value < fixed.getRawBits();
}
bool Fixed::operator>=(const Fixed &fixed) const
{
	return _value >= fixed.getRawBits();
}
bool Fixed::operator<=(const Fixed &fixed) const
{
	return _value <= fixed.getRawBits();
}
bool Fixed::operator==(const Fixed &fixed) const
{
	return _value == fixed.getRawBits();
}
bool Fixed::operator!=(const Fixed &fixed) const
{
	return _value != fixed.getRawBits();
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 < fixed2)
		return fixed1;
	return fixed2;
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 < fixed2)
		return fixed1;
	return fixed2;
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	if (fixed1 > fixed2)
		return fixed1;
	return fixed2;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
	out << value.toFloat();
	return out;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

int Fixed::toInt(void) const
{
	return (_value >> _bits);
}

float Fixed::toFloat(void) const
{
	return ((float)_value / (float)(1 << _bits));
}
