/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:53:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/20 18:32:20 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Desplaza hacia arriba todos los elementos del stack a,
 * el primero pasa a ser el ultimo
 * 
 * @param a stack a
 * @param print 1 para printar por pantalla la accion
 */
void	ra(t_stack *a, int print)
{
	if (print == 1)
		write(1, "ra\n", 3);
	if (a->len == 0)
		return ;
	rotate(a);
}

/**
 * @brief Desplaza hacia arriba todos los elementos del stack b,
 * el primero pasa a ser el ultimo
 * 
 * @param b stack b
 * @param print 1 para printar por pantalla la accion
 */
void	rb(t_stack *b, int print)
{
	if (print == 1)
		write(1, "rb\n", 3);
	if (b->len == 0)
		return ;
	rotate(b);
}

/**
 * @brief Desplaza hacia arriba todos los elementos del stack a y b,
 * el primero pasa a ser el ultimo
 * 
 * @param a stack a
 * @param b stack b
 * @param print 1 para printar por pantalla la accion
 */
void	rr(t_stack *a, t_stack *b, int print)
{
	if (print == 1)
		write(1, "rr\n", 3);
	rotate(a);
	rotate(b);
}

/**
 * @brief Desplaza hacia abajo todos los elementos del stack a,
 * el ultimo pasa a ser el primero
 * 
 * @param a stack a
 * @param print 1 para printar por pantalla la accion
 */
void	rra(t_stack *a, int print)
{
	if (print == 1)
		write(1, "rra\n", 4);
	if (a->len == 0)
		return ;
	reverse(a);
}

/**
 * @brief Desplaza hacia abajo todos los elementos del stack b,
 * el ultimo pasa a ser el primero
 * 
 * @param b stack b
 * @param print 1 para printar por pantalla la accion
 */
void	rrb(t_stack *b, int print)
{
	if (print == 1)
		write(1, "rrb\n", 4);
	if (b->len == 0)
		return ;
	reverse(b);
}
