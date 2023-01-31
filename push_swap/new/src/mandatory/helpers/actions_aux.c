/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_aux_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:53:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/20 18:39:41 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * @brief Intercambia los dos primero numeros 
 * 
 * @param stack stack a utilizar
 */
void	swap_firsts(t_stack *stack)
{
	int	aux;

	if (stack->len <= 1)
		return ;
	aux = stack->stack[0];
	stack->stack[0] = stack->stack[1];
	stack->stack[1] = aux;
}

/**
 * @brief Desplaza los elementos de la array hacia arriba y
 * añade unn numero al principio de la array
 * 
 * @param stack stack a utilizar
 * @param num numero a añadir
 */
void	push_increment(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		stack->stack[stack->len - i] = stack->stack[stack->len - 1 - i];
		i++;
	}
	stack->stack[0] = num;
}

/**
 * @brief Desplaza los elementos de la array hacia abajo 
 * 
 * @param stack stack a utilizar
 */
void	push_decrement(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
}

/**
 * @brief Rota los elementos de la array
 * 
 * @param stack stack a utilizar
 */
void	rotate(t_stack *stack)
{
	int	i;
	int	aux;

	i = 0;
	aux = stack->stack[0];
	while (i < stack->len - 1)
	{
		stack->stack[i] = stack->stack[i + 1];
		i++;
	}
	stack->stack[stack->len - 1] = aux;
}

/**
 * @brief Invierte los elementos de la array
 * 
 * @param stack stack a utilizar
 */
void	reverse(t_stack *stack)
{
	int	i;
	int	aux;

	aux = stack->stack[stack->len - 1];
	i = stack->len - 1;
	while (i > 0)
	{
		stack->stack[i] = stack->stack[i - 1];
		i--;
	}
	stack->stack[0] = aux;
}
