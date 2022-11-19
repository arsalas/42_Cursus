/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:27:50 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/20 19:41:21 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	type = "Cat";
	std::cout << "Cat construct" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat destroy" << std::endl;
}

void Cat::makeSound(void) const
{
	std::cout << "miau!" << std::endl;
}
