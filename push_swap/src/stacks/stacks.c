/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:29:27 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/24 13:32:24 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Create a stacks object
 * 
 * @param stack_a stack a
 * @param stack_b stack b
 * @param numbers total de numeros del stack
 */
void	create_stacks(t_stack *stack_a, t_stack *stack_b, int numbers)
{
	stack_a->original = ft_calloc(sizeof(int), numbers);
	stack_a->len = 0;
	if (stack_a->original == NULL)
		exit (0);
	stack_a->stack = ft_calloc(sizeof(int), numbers);
	if (stack_a->stack == NULL)
		exit (0);
	stack_b->stack = ft_calloc(sizeof(int), numbers);
	stack_b->len = 0;
	if (stack_b->stack == NULL)
		exit (0);
}

/**
 * @brief Libera la memoria reservada en los stacks 
 * 
 * @param stack_a stack a
 * @param stack_b stack b
 */
void	destroy_stacks(t_stack *stack_a, t_stack *stack_b)
{
	free(stack_a->stack);
	free(stack_b->stack);
	free(stack_b->original);
}
