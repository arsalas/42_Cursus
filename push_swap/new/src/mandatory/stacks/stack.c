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

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "stack.h"

/**
 * @brief Create a stacks object
 * 
 * @param stack_a stack a
 * @param stack_b stack b
 * @param numbers total de numeros del stack
 */
void	create_stacks(t_stack *stack_a, t_stack *stack_b, int numbers)
{
	stack_a->len = 0;
	stack_a->stack = ft_calloc(sizeof(int), numbers);
	if (stack_a->stack == NULL)
		exit (0);
	stack_b->len = 0;
	stack_b->stack = ft_calloc(sizeof(int), numbers);
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
}

/**
 * @brief Comprueba si el array esta ordendo 
 * 
 * @param stack stack a utilizar
 * @return 1 si esta ordenado 0 si no lo esta
 */
int	is_stack_sort(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->stack[i] > stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}