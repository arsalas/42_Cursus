/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:48:54 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/18 17:46:22 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
#define CONTACT_H

#include "iostream"

class Contact
{

private:
	std::string _name;
	std::string _lastName;
	std::string _nickname;
	std::string _phone;
	std::string _secret;

public:
	void setData(void);
	void printContact(void);
	std::string getName(void);
	std::string getLastName(void);
	std::string getNickname(void);
};

#endif