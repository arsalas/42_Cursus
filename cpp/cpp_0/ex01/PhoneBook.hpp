/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:48:54 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/07 20:22:14 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "iostream"
#include "Contact.hpp"

class PhoneBook
{

private:
	Contact _contacts[8];
	int _len;

	void truncateText(std::string str);

public:
	Contact getContact(int index);

	void selectAction(std::string action);
	void addContact(void);
	void searchContact(void);
};

#endif