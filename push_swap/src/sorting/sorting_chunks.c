/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_chunks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 15:21:03 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/20 19:08:36 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Crear montones ordenados en el stack b
 * 
 * @param stack_a stack a
 * @param stack_b stack b
 * @param chunk monton
 * @param limit limite de numeros
 */
static void	get_chunks(t_stack *stack_a, t_stack *stack_b, int chunk, int limit)
{
	while (get_chunk_numbers(stack_a, chunk, limit) > 0)
	{
		if (stack_a->stack[0] >= (chunk * limit)
			&& stack_a->stack[0] < (chunk * limit + limit))
		{
			pb(stack_a, stack_b, 1);
			if (get_chunk_numbers(stack_a, chunk, limit) % 2 == 0 && chunk > 0)
				rb(stack_b, 1);
		}
		else if (stack_a->stack[0] > stack_a->stack[1]
			&& stack_b->stack[1] > stack_b->stack[0])
			ss(stack_a, stack_b, 1);
		else if (positions_right_chunk(stack_a, chunk, limit)
			> stack_a->len / 2)
			rra(stack_a, 1);
		else
			ra(stack_a, 1);
	}
}

/**
 * @brief Obtiene la cantidad de montones a partir del numero total 
 * 
 * @param len Cantidad de numeros
 * @return Cantidad de montones a utilizar
 */
static int	get_quantity_chunks(int len)
{
	int	q_chunks;

	if (len > 200)
		q_chunks = 13;
	else if (len > 10)
		q_chunks = 7;
	else
		q_chunks = 2;
	return (q_chunks);
}

/**
 * @brief Metodo de ordenacion por montones
 * 
 * @param stack_a stack a
 * @param stack_b stack b
 */
void	chunk_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	chunk;
	int	limit;
	int	find;
	int	q_chunks;

	chunk = 0;
	q_chunks = get_quantity_chunks(stack_a->len);
	limit = stack_a->len / q_chunks;
	while (chunk < limit)
	{
		get_chunks(stack_a, stack_b, chunk, limit);
		chunk++;
	}
	while (stack_b->len > 0)
	{
		find = get_max(stack_b);
		while (stack_b->stack[0] != find)
		{
			if (positions_right(stack_b, find) > stack_b->len / 2)
				rrb(stack_b, 1);
			else
				rb(stack_b, 1);
		}
		pa(stack_a, stack_b, 1);
	}
}
