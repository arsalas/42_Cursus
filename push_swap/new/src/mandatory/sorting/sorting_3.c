/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:22:38 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/01 12:37:07 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sorting.h"
#include "actions.h"
#include "stack.h"
#include "maths.h"

static void	set_mixed_actions(t_option option, t_actions *actions)
{
	if (option.type == ROT_REV)
	{
		actions->ra = option.movs_rotate_a;
		actions->rrb = option.movs_reverse_b;
	}
	if (option.type == REV_ROT)
	{
		actions->rra = option.movs_reverse_a;
		actions->rb = option.movs_rotate_b;
	}
}

static void	set_pure_actions(t_option option, t_actions *actions)
{
	if (option.type == ROT)
	{
		actions->rr = min(option.movs_rotate_a, option.movs_rotate_b);
		if (option.movs_rotate_a > option.movs_rotate_b)
			actions->ra = option.movs_rotate_a - option.movs_rotate_b;
		else
			actions->rb = option.movs_rotate_b - option.movs_rotate_a;
	}
	if (option.type == REV)
	{
		actions->rrr = min(option.movs_reverse_a, option.movs_reverse_b);
		if (option.movs_reverse_a > option.movs_reverse_b)
			actions->rra = option.movs_reverse_a - option.movs_reverse_b;
		else
			actions->rrb = option.movs_reverse_b - option.movs_reverse_a;
	}
}

t_actions	calc_actions(t_option option)
{
	t_actions	actions;

	actions = new_action();
	set_pure_actions(option, &actions);
	set_mixed_actions(option, &actions);
	return (actions);
}

t_actions	get_moves_sort_a(t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	t_option	option;
	t_option	min_option;

	i = 0;
	while (i < stack_a->len)
	{
		option = get_min_actions_b(stack_a, stack_b, stack_a->stack[i]);
		if (i == 0 || option.quantity_moves < min_option.quantity_moves)
			min_option = option;
		i++;
	}
	return (calc_actions(min_option));
}

t_actions	get_moves_sort_b(t_stack *stack_a, t_stack *stack_b)
{
	int			i;
	t_option	option;
	t_option	min_option;

	i = 0;
	while (i < stack_a->len)
	{
		option = get_min_actions_a(stack_a, stack_b, stack_a->stack[i]);
		if (i == 0 || option.quantity_moves < min_option.quantity_moves)
			min_option = option;
		i++;
	}
	return (calc_actions(min_option));
}
