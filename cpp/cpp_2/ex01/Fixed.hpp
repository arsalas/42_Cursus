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

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int _point;
	static const int _nbits = 8;

public:
	Fixed(void);
	Fixed(const int point);
	Fixed(const float point);
	Fixed(Fixed &cpy);

	~Fixed(void);

	Fixed &operator=(const Fixed &cpy);
	std::ostream &operator<<(std::ostream &out, Fixed const &value);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void);
	int toInt(void);
};

#endif