/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:30:01 by marvin            #+#    #+#             */
/*   Updated: 2022/12/18 21:30:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0){};

Point::Point(const Fixed x, const Fixed y) : _x(x), _y(y){};

Point::Point(const Point &point) : _x(point.getX()), _y(point.getY()) {}

Point::~Point()
{
	// std::cout << "Destroy Point" << std::endl;
}

Point &Point::operator=(const Point &point)
{
	// std::cout << "Asignation operator called" << std::endl;
	return *new Point(point.getX(), point.getY());
}

Fixed Point::getX() const
{
	return _x;
}

Fixed Point::getY() const
{
	return _y;
}

float Point::getXtoFloat() const
{
	return _x.toFloat();
}

float Point::getYtoFloat() const
{
	return _y.toFloat();
}
