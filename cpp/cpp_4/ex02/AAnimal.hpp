/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/20 19:40:57 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_H
#define Animal_H
#include <iostream>

class AAnimal
{
protected:
	std::string _type;

public:
	virtual void makeSound() const = 0;
	virtual std::string getType() const = 0;
};

#endif