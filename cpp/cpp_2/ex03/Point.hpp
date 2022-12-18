/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 22:24:01 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
#define POINT_H

#include <iostream>
#include "Fixed.hpp"

class Point
{
private:
	Fixed const _x;
	Fixed const _y;

public:
	Point();
	Point(const Fixed x, const Fixed y);
	Point(const Point &point);
	~Point();

	Point &operator=(const Point &point);

	Fixed getX() const;
	Fixed getY() const;
	float getXtoFloat() const;
	float getYtoFloat() const;

};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif