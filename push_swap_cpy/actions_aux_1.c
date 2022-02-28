/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:53:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/21 14:34:23 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_len(int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

void	swap_firsts(int *stack)
{
	int	aux;

	if (get_len(stack) <= 1)
		return ;
	aux = stack[0];
	stack[0] = stack[1];
	stack[1] = aux;
}

void	push_increment(int *stack, int num)
{
	int	len;
	int	i;

	len = get_len(stack);
	i = 0;
	while (i < len)
	{
		stack[len - i] = stack[len - 1 - i];
		i++;
	}
	stack[0] = num;
}

void	push_decrement(int *stack)
{
	int	len;
	int	i;

	len = get_len(stack);
	i = 0;
	while (i < len)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = '\0';
}

void	rotate(int *stack)
{
	int	len;
	int	i;
	int	aux;

	len = get_len(stack);
	i = 0;
	aux = stack[0];
	while (i < len)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = aux;
}
