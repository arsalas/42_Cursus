/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:32:22 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/24 13:27:30 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Encuentra la posicion de un numero en la array del stack
 * 
 * @param stack stack a utilizar
 * @param n numero a buscar
 * @return int posicion del numero
 */
int	find_position(t_stack *stack, int n)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (i < stack->len)
	{
		if (stack->original[i] < n)
			c++;
		i++;
	}
	return (c);
}

/**
 * @brief Guarda en el stack las posiciones que deberian tener los numeros 
 * 
 * @param stack stack a utilizar
 */
void	get_positions(t_stack *stack)
{
	int	d;

	d = 0;
	{
		while (d < stack->len)
		{
			stack->stack[d] = find_position(stack, stack->original[d]);
			d++;
		}
	}
}
