/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:36:23 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/18 18:13:02 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "colors.hpp"

Contact PhoneBook::getContact(int index)
{
	return this->_contacts[index];
}

void PhoneBook::selectAction(std::string action)
{
	if (action == "EXIT")
		exit(0);
	else if (action == "ADD")
		PhoneBook::addContact();
	else if (action == "SEARCH")
		searchContact();
	else
		std::cout << KRED "Accion no valida" RST << std::endl;
}
void PhoneBook::addContact(void)
{
	if (this->_len == 8)
		this->_contacts[7].setData();
	else
	{
		this->_contacts[this->_len].setData();
		this->_len += 1;
	}
}

void PhoneBook::truncateText(std::string str)
{
    size_t i;

    i = 0;
    if (str.length() > 9)
    {
        while (str[i] && i < 9)
        {
            std::cout << str[i];
            i++;
        }
        std::cout << ".";
    }
    else
    {
        i = str.length();
        while (i < 10)
        {
            std::cout << " ";
            i++;
        }
        std::cout << str;
    }
}

void PhoneBook::searchContact(void)
{
	int i;

	i = 0;
	std::cout <<KCYN "|";
	std::cout << " ";
	std::cout << KCYN"|" KBLU;
	truncateText("Nombre");
	std::cout << KCYN "|" KBLU;
	truncateText("Apellidos");
	std::cout << KCYN "|" KBLU;
	truncateText("Apodo");
	std::cout << KCYN "|\n"RST;
	while (i < this->_len)
	{
		std::cout << KCYN"|"RST;
		std::cout << i + 1;
		std::cout << KCYN"|"RST;
		truncateText(_contacts[i].getName());
		std::cout << KCYN"|"RST;
		truncateText(this->_contacts[i].getLastName());
		std::cout << KCYN"|"RST;
		truncateText(this->_contacts[i].getNickname());
		std::cout << KCYN"|\n"RST;
		i++;
	}
	if (i > 0)
	{
		std::cout << KYEL "Selecciona contacto: " RST << std::endl;
		std::cin >> i;
		if (i <= _len)
			this->_contacts[i - 1].printContact();
	}
}
