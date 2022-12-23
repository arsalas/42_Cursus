/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/23 17:19:12 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_H
#define Dog_H
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{

private:
	Brain *_brain;

public:
	~Dog();
	Dog();
	Dog(const Dog &dog);

	Dog &operator=(const Dog &dog);

	void makeSound() const;
};

#endif