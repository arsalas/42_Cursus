/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/20 19:41:03 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_H
#define WrongCat_H
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:
	~WrongCat();
	WrongCat();
	WrongCat(const WrongCat &cat);

	WrongCat &operator=(const WrongCat &cat);

	void makeSound() const;
};

#endif