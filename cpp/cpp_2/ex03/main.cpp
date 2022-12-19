/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:00:55 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/19 12:55:54 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

void testPoints(std::string title, float pX, float pY)
{
	Point p1(1.0f, 1.0f);
	Point p2(2.0f, 1.0f);
	Point p3(1.5f, 2.0f);

	Point point(pX, pY);
	std::cout << title << std::endl;
	std::cout << "p1 is in: " << p1.getX() << ", " << p1.getY() << std::endl;
	std::cout << "p2 is in: " << p2.getX() << ", " << p2.getY() << std::endl;
	std::cout << "p3 is in: " << p3.getX() << ", " << p3.getY() << std::endl;

	std::cout << "point is in: " << point.getX() << ", " << point.getY() << std::endl;
	std::cout << "point is inside: " << (bsp(p1, p2, p3, point) ? "YES" : "NO") << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	testPoints("Point inside the triangle", 1.5f, 1.5f);
	testPoints("Point in one vertex", 1.0f, 1.0f);
	testPoints("Point in one edge", 1.5f, 1.0f);
	testPoints("Point outside the triangle", 1.5f, 4.0f);

	return 0;
}