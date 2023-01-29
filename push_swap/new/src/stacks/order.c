/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:24:28 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/24 13:30:12 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Comprueba si el array esta ordendo 
 * 
 * @param stack stack a utilizar
 * @return 1 si esta ordenado 0 si no lo esta
 */
int	is_order(t_stack *stack)
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

/**
 * @brief Comprueba si la array esta ordernada de manera inversa
 * 
 * @param stack stack a utilizar
 * @return 1 si esta ordenado 0 si no lo esta 
 */
int	is_order_reverse(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (stack->stack[i] < stack->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Comprueba si la array esta ordernada de manera inversa por digitos
 * 
 * @param stack stack a utilizar
 * @param digit digito a utilizar
 * @return 1 si esta ordenado 0 si no lo esta  
 */
int	is_order_reverse_digit(t_stack *stack, int digit)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (get_digit(stack->stack[i], digit)
			< get_digit(stack->stack[i + 1], digit))
			return (0);
		i++;
	}
	return (1);
}
