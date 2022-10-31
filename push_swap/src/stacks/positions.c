/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:31:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/24 13:31:33 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Cuenta los numeros que hay a la derecha del primer numero 
 * hasta encontrar el digito del numero a buscar 
 * 
 * @param stack stack a utilizar
 * @param find numero a buscar
 * @param digit digito a utilizar
 * @return numero de posiciones a la derecha del numero
 */
int	positions_right_digit(t_stack *stack, int find, int digit)
{
	int	i;

	i = 0;
	while (i < stack->len && get_digit(stack->stack[i], digit) != find)
		i++;
	return (i);
}

/**
 * @brief Cuenta los numeros que hay a la derecha del primer 
 *  numero hasta encontrar el numero a buscar 
 * 
 * @param stack stack a utilizar
 * @param find numero a buscar
 * @return int numero de posiciones a la derecha del numero
 */
int	positions_right(t_stack *stack, int find)
{
	int	i;

	i = 0;
	while (i < stack->len && stack->stack[i] != find)
		i++;
	return (i);
}
