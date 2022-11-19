/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:cpp_0/ex01/PhoneBook.hpp
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:48:54 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/18 18:06:29 by aramirez         ###   ########.fr       */
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
========
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:04:40 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/20 18:32:50 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Desplaza hacia abajo todos los elementos del stack a y b,
 * el ultimo pasa a ser el primero
 * 
 * @param a stack a
 * @param b stack b
 * @param print 1 para printar por pantalla la accion
 */
void	rrr(t_stack *a, t_stack *b, int print)
{
	if (print == 1)
		write(1, "rrr\n", 4);
	reverse(a);
	reverse(b);
}
>>>>>>>> 8ce7687 (update):push_swap/src/actions/actions_3.c
