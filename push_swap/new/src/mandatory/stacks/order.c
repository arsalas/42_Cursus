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

#include "stack.h"

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
