/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/21 16:22:21 by aramirez         ###   ########.fr       */
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
	Brain *brain;

public:
	Dog(void);
	~Dog(void);
	void makeSound(void) const;
	
};

#endif