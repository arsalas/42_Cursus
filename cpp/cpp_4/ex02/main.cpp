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

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	Dog *dog = new Dog();
	Cat *cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	cat->makeSound();
	dog->makeSound();
	delete dog;
	delete cat;

	{
		std::cout << "-----Copy-----" << std::endl;
		Cat cat = Cat();
		cat.setIdea("Idea 1");
		cat.setIdea("Idea 2");
		Cat copy = Cat(cat);
		std::cout << "Cat: " << cat.getIdea(0) << std::endl;
		std::cout << "Cat copy: " << copy.getIdea(0) << std::endl;
		std::cout << "Cat: " << cat.getIdea(1) << std::endl;
		std::cout << "Cat copy: "
				  << copy.getIdea(1) << std::endl;
	}

	return 0;
}