/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:01:05 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/07 20:56:35 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "colors.hpp"

int main(void)
{
	std::string action;
	PhoneBook phoneBook;

	while (true)
	{
		std::cout << KMAG "Introduce instruccion: (ADD | SEARCH | EXIT)" RST << "\n";
		std::cin >> action;
		phoneBook.selectAction(action);
	}
	return (0);
}