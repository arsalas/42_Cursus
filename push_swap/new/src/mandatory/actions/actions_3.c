/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:04:40 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/20 18:32:50 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack.h"
#include "helpers.h"

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
