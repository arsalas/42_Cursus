
#include "stack.h"
#include "sorting.h"
#include "actions.h"
#include "maths.h"

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

t_option get_min_actions(t_stack *stack_a, t_stack *stack_b, int obj)
{
	t_option option;

	option = new_option();
	option.movs_rotate_a = get_movs_rotate(stack_a, obj);
	option.movs_rotate_b = get_movs_rotate(stack_b, get_num_to_top_b(stack_b, obj));
	option.movs_reverse_a = get_movs_reverse(stack_a, obj);
	option.movs_reverse_b = get_movs_reverse(stack_b, get_num_to_top_b(stack_b, obj));
	calc_min_actions_by_moves(&option);
	return (option);
}

t_actions calc_actions(t_option option)
{
	t_actions actions;

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
		t_option option = get_min_actions(stack_a, stack_b, stack_a->stack[i]);

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
			get_moves_order_b(stack_a, stack_b),
			stack_a, stack_b);
		pa(stack_a, stack_b, 1);
	}
}

void sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_actions moves;

	if (is_stack_sort(stack_a))
		return;
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	push_to_b(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
	move_to_top(stack_a);
}