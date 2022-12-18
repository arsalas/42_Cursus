/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 22:37:45 by marvin            #+#    #+#             */
/*   Updated: 2022/12/18 22:37:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static float calcScalar(Point a, Point b, Point c)
{
	return (a.getXtoFloat() - c.getXtoFloat()) * (b.getYtoFloat() - c.getYtoFloat()) - (b.getXtoFloat() - c.getXtoFloat()) * (a.getYtoFloat() - c.getYtoFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{

	float p1, p2, p3;

	p1 = calcScalar(a, b, point);
	p2 = calcScalar(b, c, point);
	p3 = calcScalar(c, a, point);
	if ((p1 > 0 && p2 > 0 && p3 > 0) || (p1 < 0 && p2 < 0 && p3 < 0))
		return true;
	return false;
}
