/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 12:04:40 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/01 12:04:46 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "actions.h"
#include "stack.h"
#include "helpers.h"

/**
 * @brief Desplaza hacia abajo todos los elementos del stack a y b,
 * el ultimo pasa a ser el primero
 * 
 * @param a stack a
 * @param b stack b
 * @param print 1 para printar por pantalla la accion
 */
void	rrr(t_stack *a, t_stack *b, int print)
{
	if (print == 1)
		write(1, "rrr\n", 4);
	reverse(a);
	reverse(b);
}

t_actions	new_action(void)
{
	t_actions	actions;

	actions.ra = 0;
	actions.rb = 0;
	actions.rr = 0;
	actions.rra = 0;
	actions.rrb = 0;
	actions.rrr = 0;
	return (actions);
}

static void	execute_actions_rotate(
	t_actions actions, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < actions.ra)
	{
		ra(stack_a, 1);
		i++;
	}
	i = 0;
	while (i < actions.rb)
	{
		rb(stack_b, 1);
		i++;
	}
	i = 0;
	while (i < actions.rr)
	{
		rr(stack_a, stack_b, 1);
		i++;
	}
}

static void	execute_actions_rotate_reverse(
	t_actions actions, t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	i = 0;
	while (i < actions.rra)
	{
		rra(stack_a, 1);
		i++;
	}
	i = 0;
	while (i < actions.rrb)
	{
		rrb(stack_b, 1);
		i++;
	}
	i = 0;
	while (i < actions.rrr)
	{
		rrr(stack_a, stack_b, 1);
		i++;
	}
}

void	execute_actions(t_actions actions, t_stack *stack_a, t_stack *stack_b)
{
	execute_actions_rotate(actions, stack_a, stack_b);
	execute_actions_rotate_reverse(actions, stack_a, stack_b);
}
