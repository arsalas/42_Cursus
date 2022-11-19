/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/21 15:25:11 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_H
#define Animal_H
#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	virtual ~Animal(void);
	virtual std::string getType();
	virtual void makeSound() const;
	
};

#endif