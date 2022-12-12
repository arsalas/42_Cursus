/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:33:08 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 15:38:54 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "colors.hpp"

void Contact::setData(void)
{
	std::cout << KBLU "Introduce nombre:" RST << std::endl;
	std::getline(std::cin, this->_name);
	std::cout << KBLU "Introduce apellido:" RST << std::endl;
	std::getline(std::cin, this->_lastName);
	std::cout << KBLU "Introduce apodo:" RST << std::endl;
	std::getline(std::cin, this->_nickname);
	std::cout << KBLU "Introduce telefono:" RST << std::endl;
	std::getline(std::cin, this->_phone);
	std::cout << KBLU "Introduce secreto mas oscuro:" RST << std::endl;
	std::getline(std::cin, this->_secret);
}

void Contact::printContact(void)
{
	std::cout << KGRN "Nombre: " RST << std::endl;
	std::cout << this->_name << std::endl;
	std::cout << KGRN "Apellido: " RST << std::endl;
	std::cout << this->_lastName << std::endl;
	std::cout << KGRN "Apodo: " RST << std::endl;
	std::cout << this->_nickname << std::endl;
	std::cout << KGRN "Telefono: " RST << std::endl;
	std::cout << this->_phone << std::endl;
	std::cout << KGRN "Sectreto mas oscuro: " RST << std::endl;
	std::cout << this->_secret << std::endl;
}

std::string Contact::getName(void)
{
	return this->_name;
}
std::string Contact::getLastName(void)
{
	return this->_lastName;
}
std::string Contact::getNickname(void)
{
	return this->_nickname;
}
