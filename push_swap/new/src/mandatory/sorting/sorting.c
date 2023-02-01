#include <limits.h>

#include "stack.h"
#include "sorting.h"
#include "actions.h"
#include "maths.h"

//stack
int get_movs_rotate(t_stack *stack, int num)
{
	int i = 0;

	while (i < stack->len)
	{
		if (stack->stack[i] == num)
			return (i);
		i++;
	}
	return (i);
}

//stack
int get_movs_reverse(t_stack *stack, int num)
{
	if (stack->stack[0] == num)
		return (0);
	return (stack->len - get_movs_rotate(stack, num));
}

int get_type(int a, int b, int c, int d)
{
	if (a <= b && a <= c && a <= d)
		return (0);
	if (b <= a && b <= c && b <= d)
		return (1);
	if (c <= a && c <= b && c <= d)
		return (2);
	return (3);
}

//stack
int get_max_num_stack(t_stack *stack)
{
	int max;
	int i;

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

//stack
int get_min_num_stack(t_stack *stack)
{
	int min;
	int i;

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

int get_min_num_stack_position(t_stack *stack)
{
	int min;
	int pos;
	int i;

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



int get_num_to_top_b(t_stack *stack, int num)
{
	int max;
	int min;

	max = get_max_num_stack(stack);
	min = get_min_num_stack(stack);
	if (num > max || num < min)
		return (max);
	int i = 0;
	min = INT_MIN;
	while (i < stack->len)
	{
		if (stack->stack[i] < num && stack->stack[i] > min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int get_num_to_top_a(t_stack *stack, int num)
{
	int max;
	int min;

	max = get_max_num_stack(stack);
	min = get_min_num_stack(stack);
	if (num > max || num < min)
		return (min);
	int i = 0;
	min = INT_MAX;
	while (i < stack->len)
	{
		if (stack->stack[i] > num && stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

void calc_min_actions_by_moves(t_option *option)
{
	int rot;
	int rev;
	int rot_rev;
	int rev_rot;

	rot = max(option->movs_rotate_a, option->movs_rotate_b);
	rev = max(option->movs_reverse_a, option->movs_reverse_b);
	rot_rev = option->movs_rotate_a + option->movs_reverse_b;
	rev_rot = option->movs_reverse_a + option->movs_rotate_b;
	option->quantity_moves = min(min(rot, rev), min(rot_rev, rev_rot));
	option->type = get_type(rot, rev, rot_rev, rev_rot);
}

t_option get_min_actions_a(t_stack *stack_a, t_stack *stack_b, int obj)
{
	t_option option;

	option.movs_rotate_a = get_movs_rotate(stack_a, obj);
	option.movs_rotate_b = get_movs_rotate(stack_b, get_num_to_top_b(stack_b, obj));
	option.movs_reverse_a = get_movs_reverse(stack_a, obj);
	option.movs_reverse_b = get_movs_reverse(stack_b, get_num_to_top_b(stack_b, obj));
	calc_min_actions_by_moves(&option);
	return (option);
}

t_option get_min_actions_b(t_stack *stack_a, t_stack *stack_b, int obj)
{
	t_option option;

	option.movs_rotate_a = get_movs_rotate(stack_a, obj);
	option.movs_rotate_b = get_movs_rotate(stack_b, get_num_to_top_a(stack_b, obj));
	option.movs_reverse_a = get_movs_reverse(stack_a, obj);
	option.movs_reverse_b = get_movs_reverse(stack_b, get_num_to_top_a(stack_b, obj));
	calc_min_actions_by_moves(&option);
	return (option);
}

t_actions calc_actions(t_option option)
{
	t_actions actions;

	actions = new_action();
	if (option.type == ROT)
	{
		actions.rr = min(option.movs_rotate_a, option.movs_rotate_b);
		if (option.movs_rotate_a > option.movs_rotate_b)
			actions.ra = option.movs_rotate_a - option.movs_rotate_b;
		else
			actions.rb = option.movs_rotate_b - option.movs_rotate_a;
	}
	else if (option.type == REV)
	{
		actions.rrr = min(option.movs_reverse_a, option.movs_reverse_b);
		if (option.movs_reverse_a > option.movs_reverse_b)
			actions.rra = option.movs_reverse_a - option.movs_reverse_b;
		else
			actions.rrb = option.movs_reverse_b - option.movs_reverse_a;
	}
	else if (option.type == ROT_REV)
	{
		actions.ra = option.movs_rotate_a;
		actions.rrb = option.movs_reverse_b;
	}
	else if (option.type == REV_ROT)
	{
		actions.rra = option.movs_reverse_a;
		actions.rb = option.movs_rotate_b;
	}
	return (actions);
}

t_actions get_moves_sort_a(t_stack *stack_a, t_stack *stack_b)
{
	t_option option;
	t_option min_option;
	int i;

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

t_actions get_moves_sort_b(t_stack *stack_a, t_stack *stack_b)
{
	t_option option;
	t_option min_option;
	int i;

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

void push_to_b(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->len > 2)
	{
		execute_actions(
			get_moves_sort_a(stack_a, stack_b),
			stack_a, stack_b);
		pb(stack_a, stack_b, 1);
	}
}

void push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->len > 0)
	{
		execute_actions(
			get_moves_sort_b(stack_a, stack_b),
			stack_a, stack_b);
		pa(stack_a, stack_b, 1);
	}
}

void move_to_top(t_stack *stack_a)
{
	int min = get_min_num_stack(stack_a);
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

void sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (is_stack_sort(stack_a))
		return;
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	push_to_b(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
	move_to_top(stack_a);
}