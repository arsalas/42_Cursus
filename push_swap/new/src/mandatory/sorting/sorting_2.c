/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:11:51 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/01 12:31:51 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "stack.h"
#include "sorting.h"

t_options_type	get_type(int rot, int rev, int rot_rev, int rev_rot)
{
	if (rot <= rev && rot <= rot_rev && rot <= rev_rot)
		return (ROT);
	if (rev <= rot && rev <= rot_rev && rev <= rev_rot)
		return (REV);
	if (rot_rev <= rot && rot_rev <= rev && rot_rev <= rev_rot)
		return (ROT_REV);
	return (REV_ROT);
}

static int	get_num_to_top_b(t_stack *stack, int num)
{
	int	max;
	int	min;
	int	i;

	i = 0;
	max = get_max_num_stack(stack);
	min = get_min_num_stack(stack);
	if (num > max || num < min)
		return (max);
	min = INT_MIN;
	while (i < stack->len)
	{
		if (stack->stack[i] < num && stack->stack[i] > min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

static int	get_num_to_top_a(t_stack *stack, int num)
{
	int	max;
	int	min;
	int	i;

	i = 0;
	max = get_max_num_stack(stack);
	min = get_min_num_stack(stack);
	if (num > max || num < min)
		return (min);
	min = INT_MAX;
	while (i < stack->len)
	{
		if (stack->stack[i] > num && stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

t_option	get_min_actions_a(t_stack *stack_a, t_stack *stack_b, int obj)
{
	t_option	option;

	option.movs_rotate_a = get_movs_rotate(stack_a, obj);
	option.movs_rotate_b = get_movs_rotate(
			stack_b, get_num_to_top_b(stack_b, obj));
	option.movs_reverse_a = get_movs_reverse(stack_a, obj);
	option.movs_reverse_b = get_movs_reverse(
			stack_b, get_num_to_top_b(stack_b, obj));
	calc_min_actions_by_moves(&option);
	return (option);
}

t_option	get_min_actions_b(t_stack *stack_a, t_stack *stack_b, int obj)
{
	t_option	option;

	option.movs_rotate_a = get_movs_rotate(stack_a, obj);
	option.movs_rotate_b = get_movs_rotate(
			stack_b, get_num_to_top_a(stack_b, obj));
	option.movs_reverse_a = get_movs_reverse(stack_a, obj);
	option.movs_reverse_b = get_movs_reverse(
			stack_b, get_num_to_top_a(stack_b, obj));
	calc_min_actions_by_moves(&option);
	return (option);
}
