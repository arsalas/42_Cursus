/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:14:05 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/01 12:15:34 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int	get_movs_rotate(t_stack *stack, int num)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->stack[i] == num)
			return (i);
		i++;
	}
	return (i);
}

int	get_movs_reverse(t_stack *stack, int num)
{
	if (stack->stack[0] == num)
		return (0);
	return (stack->len - get_movs_rotate(stack, num));
}

int	get_max_num_stack(t_stack *stack)
{
	int	max;
	int	i;

	if (stack->len == 0)
		return (0);
	max = stack->stack[0];
	i = 1;
	while (i < stack->len)
	{
		if (stack->stack[i] > max)
			max = stack->stack[i];
		i++;
	}
	return (max);
}

int	get_min_num_stack(t_stack *stack)
{
	int	min;
	int	i;

	if (stack->len == 0)
		return (0);
	min = stack->stack[0];
	i = 1;
	while (i < stack->len)
	{
		if (stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int	get_min_num_stack_position(t_stack *stack)
{
	int	min;
	int	pos;
	int	i;

	if (stack->len == 0)
		return (0);
	min = stack->stack[0];
	pos = 0;
	i = 1;
	while (i < stack->len)
	{
		if (stack->stack[i] < min)
		{
			min = stack->stack[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}
