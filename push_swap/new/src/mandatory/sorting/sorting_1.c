/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:07:10 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/01 12:37:25 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "sorting.h"
#include "actions.h"
#include "maths.h"

void	calc_min_actions_by_moves(t_option *option)
{
	int	rot;
	int	rev;
	int	rot_rev;
	int	rev_rot;

	rot = max(option->movs_rotate_a, option->movs_rotate_b);
	rev = max(option->movs_reverse_a, option->movs_reverse_b);
	rot_rev = option->movs_rotate_a + option->movs_reverse_b;
	rev_rot = option->movs_reverse_a + option->movs_rotate_b;
	option->quantity_moves = min(min(rot, rev), min(rot_rev, rev_rot));
	option->type = get_type(rot, rev, rot_rev, rev_rot);
}

static void	push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->len > 2)
	{
		execute_actions(
			get_moves_sort_a(stack_a, stack_b),
			stack_a, stack_b);
		pb(stack_a, stack_b, 1);
	}
}

static void	push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->len > 0)
	{
		execute_actions(
			get_moves_sort_b(stack_a, stack_b),
			stack_a, stack_b);
		pa(stack_a, stack_b, 1);
	}
}

static void	move_to_top(t_stack *stack_a)
{
	int	min;

	min = get_min_num_stack(stack_a);
	if (get_min_num_stack_position(stack_a) > stack_a->len / 2)
	{
		while (stack_a->stack[0] != min)
			rra(stack_a, 1);
	}
	else
	{
		while (stack_a->stack[0] != min)
			ra(stack_a, 1);
	}
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (is_stack_sort(stack_a))
		return ;
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	push_to_b(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
	move_to_top(stack_a);
}
