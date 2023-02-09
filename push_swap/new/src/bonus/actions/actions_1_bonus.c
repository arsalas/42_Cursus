/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:53:32 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/09 15:32:44 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "stack_bonus.h"
#include "helpers_bonus.h"

/**
 * @brief  Intercambia los dos primeros numeros del stack a 
 * si hay mas de dos elementos
 * 
 * @param a stack a
 * @param print 1 para printar por pantalla la accion
 */
void	sa(t_stack *a, int print)
{
	if (print == 1)
		write(1, "sa\n", 3);
	swap_firsts(a);
}

/**
 * @brief Intercambia los dos primeros numeros del stack b 
 * si hay mas de dos elementos
 * 
 * @param b stack b
 * @param print 1 para printar por pantalla la accion
 */
void	sb(t_stack *b, int print)
{
	if (print == 1)
		write(1, "sb\n", 3);
	swap_firsts(b);
}

/**
 * @brief Intercambia los dos primeros numeros del stack a y b 
 * si hay mas de dos elementos
 * 
 * @param a stack a
 * @param b stack b
 * @param print 1 para printar por pantalla la accion
 */
void	ss(t_stack *a, t_stack *b, int print)
{
	if (print == 1)
		write(1, "ss\n", 3);
	swap_firsts(a);
	swap_firsts(b);
}

/**
 * @brief Toma el primer elemento del stack b y lo pone encima de a
 * No hace nada si a esta vacio
 * 
 * @param a stack a
 * @param b stack b
 * @param print 1 para printar por pantalla la accion
 */
void	pa(t_stack *a, t_stack *b, int print)
{
	if (print == 1)
		write(1, "pa\n", 3);
	if (b->len == 0)
		return ;
	push_increment(a, b->stack[0]);
	push_decrement(b);
	a->len++;
	b->len--;
}

/**
 * @brief Pone el primer elemento del stack a y lo pone en b
 *  No hace nada si a esta vacio
 * 
 * @param a stack a
 * @param b stack b
 * @param print 1 para printar por pantalla la accion
 */
void	pb(t_stack *a, t_stack *b, int print)
{
	if (print == 1)
		write(1, "pb\n", 3);
	if (a->len == 0)
		return ;
	push_increment(b, a->stack[0]);
	push_decrement(a);
	a->len--;
	b->len++;
}
