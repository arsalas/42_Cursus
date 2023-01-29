/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_aux_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:53:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/20 18:43:29 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Encuentra el siguiente numero a buscar en un stack 
 * 
 * @param stack stack a utilizar
 * @param num numero a comparar
 * @return numero a buscar
 */
int	find_next_number(t_stack *stack, int num)
{
	int	i;
	int	aux;

	i = 0;
	aux = -1;
	while (i < stack->len)
	{
		if (stack->stack[i] < num && stack->stack[i] > aux)
			aux = stack->stack[i];
		i++;
	}
	return (aux);
}

/**
 * @brief Obtiene el numero max de un stack 
 * 
 * @param stack stack a utilizar
 * @return numero maximo del stack
 */
int	get_max(t_stack *stack)
{
	int	max;
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (i == 0)
			max = stack->stack[i];
		else if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

/**
 * @brief Obtiene la cantidad de numeros de un intervalo(chunk)
 
 * 
 * @param stack stack a utilizar
 * @param chunk cantidad de montones
 * @param nums numeros del stack
 * @return cantidad de numeros por chunk 
 */
int	get_chunk_numbers(t_stack *stack, int chunk, int nums)
{
	int	c;
	int	i;

	i = 0;
	c = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] >= chunk * nums
			&& stack->stack[i] < chunk * nums + nums)
			c++;
		i++;
	}
	return (c);
}

/**
 * @brief Obtiene cuantas posiciones hacia la derecha hay un un stack con 
 * un numero pasado como argumento
 * 
 * @param stack stack a utilizar
 * @param chunk montones utilizados
 * @param nums numeros por chunk
 * @return posiciones a desplazarse hacia la derecha
 */
int	positions_right_chunk(t_stack *stack, int chunk, int nums)
{
	int	i;

	i = 0;
	while (i < stack->len && !(stack->stack[i] >= chunk * nums
			&& stack->stack[i] < chunk * nums + nums))
		i++;
	return (i);
}
