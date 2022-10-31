/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:30:48 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/20 18:59:35 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Comprueba si el primer numero de la array es el mas pequeño 
 * 
 * @param stack stack a comprobar
 * @param len total de numeros
 * @return 1 es el mas pequeño 0 si no lo es 
 */
int	is_smallest_stack(t_stack *stack, int len)
{
	int	i;
	int	c;

	i = 1;
	c = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] > stack->stack[0])
			c++;
		i++;
	}
	if ((len / 2) <= c)
		return (1);
	return (0);
}

/**
 * @brief Obtiene el numero mas grande de un stack
 * 
 * @param stack stack a utilizar
 * @return numero maximo
 */
int	get_max_num(t_stack *stack)
{
	int	i;
	int	num;

	i = 1;
	num = stack->stack[0];
	while (i < stack->len)
	{
		if (stack->stack[i] > num)
			num = stack->stack[i];
		i++;
	}
	return (num);
}

/**
 * @brief Comprueba si el digito del numero dado es el mas pequeño del stack
 * 
 * @param stack stack a utilizar
 * @param num numero a comprobar
 * @param digit digito a utilizar
 * @return 1 si es el mas prqueño
 */
int	is_smallest_digit(t_stack *stack, int num, int digit)
{
	int	i;

	i = 1;
	while (i < stack->len)
	{
		if (get_digit(stack->stack[i], digit) < num)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Comprueba si el numero dado es el mas pqueño del stack
 * 
 * @param stack stack a utilizar
 * @param num numero a buscar
 * @return 1 si es el mas pequeño
 */
int	is_smallest(t_stack *stack, int num)
{
	int	i;

	i = 1;
	while (i < stack->len)
	{
		if (stack->stack[i] < num)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Comprueba si el la array esta ordenada por digito 
 * 
 * @param stack stack a utilizar
 * @param digit digito a utilizar
 * @return 1 si esta ordenado
 */
int	is_order_digit(t_stack *stack, int digit)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		if (get_digit(stack->stack[i], digit)
			> get_digit(stack->stack[i + 1], digit))
			return (0);
		i++;
	}
	return (1);
}
