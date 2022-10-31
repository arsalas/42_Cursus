/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_simple.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:21:03 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/20 18:51:24 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Busca el numero maximo del stack b y lo pone el primero y 
 * paso todo el stack de b a a
 * 
 * @param stack_a stack a
 * @param stack_b stack b
 */
static void	push_order_max(t_stack *stack_a, t_stack *stack_b)
{
	int	find;

	find = get_max(stack_b);
	while (stack_b->stack[0] != find)
	{
		if (positions_right(stack_b, find) > stack_b->len / 2)
			rrb(stack_b, 1);
		else
			rb(stack_b, 1);
	}
	while (stack_b->len > 0)
		pa(stack_a, stack_b, 1);
}

/**
 * @brief Ordena pasando todo a un stack y devolviendo los numeros mayores
 * 
 * @param stack_a srtack a
 * @param stack_b srtack b
 */
void	simple_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	find;

	while (stack_a->len > 0)
	{
		while (stack_b->len < 2)
			pb(stack_a, stack_b, 1);
		find = find_next_number(stack_b, stack_a->stack[0]);
		if (find == -1)
			find = get_max(stack_b);
		while (stack_b->stack[0] != find)
		{
			if (positions_right(stack_b, find) > stack_b->len / 2)
				rrb(stack_b, 1);
			else
				rb(stack_b, 1);
		}
		pb(stack_a, stack_b, 1);
	}
	push_order_max(stack_a, stack_b);
}
