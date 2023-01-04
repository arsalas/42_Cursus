/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:30:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/23 19:56:42 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	const size_t number = 10;
	Animal *animals[number];

	std::cout << "-----Create animals-----" << std::endl;
	for (size_t i = 0; i < number; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "-----Delete animals-----" << std::endl;
	for (size_t i = 0; i < number; i++)
	{
		delete animals[i];
	}

	std::cout << "-----Copy-----" << std::endl;
	Cat cat = Cat();
	cat.setIdea("Idea 1");
	cat.setIdea("Idea 2");
	Cat copy = Cat(cat);
	std::cout << "Cat: " << cat.getIdea(0) << std::endl;
	std::cout << "Cat copy: " << copy.getIdea(0) << std::endl;
	std::cout << "Cat: " << cat.getIdea(1) << std::endl;
	std::cout << "Cat copy: " << copy.getIdea(1) << std::endl;
	return (0);
}