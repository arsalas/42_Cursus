/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/23 17:18:42 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_H
#define Cat_H
#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{

private:
	Brain *_brain;

public:
	~Cat();
	Cat();
	Cat(const Cat &cat);

	Cat &operator=(const Cat &cat);

	void makeSound() const;
};

#endif