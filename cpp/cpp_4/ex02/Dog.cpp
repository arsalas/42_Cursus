/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:27:50 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/21 16:24:25 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	type = "Dog";
	std::cout << "Dog construct" << std::endl;
	brain = new Brain();
}

Dog::~Dog(void)
{
	std::cout << "Dog destroy" << std::endl;
	delete brain;
}

void Dog::makeSound(void) const
{
	std::cout << "guau!" << std::endl;
}
