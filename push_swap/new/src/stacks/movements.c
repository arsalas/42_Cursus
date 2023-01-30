/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:34:48 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/24 17:50:36 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_movements
{
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
} t_movements;

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

int get_movs_reverse(t_stack *stack, int num)
{
	if (stack->stack[0] == num)
		return (0);
	return (stack->len - get_movs_rotate(stack, num));
}

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

int get_max_num_stack_position(t_stack *stack)
{
	int max;
	int pos;
	int i;

	if (stack->len == 0)
		return (0);
	max = stack->stack[0];
	pos = 0;
	i = 1;
	while (i < stack->len)
	{
		if (stack->stack[i] > max)
		{
			max = stack->stack[i];
			pos = i;
		}
		i++;
	}
	return (pos);
}

int get_num_to_top_b(t_stack *stack, int num) // 3
{
	int max;
	int min;

	max = get_max_num_stack(stack); // 7
	min = get_min_num_stack(stack); // 1
	if (num > max || num < min)
		return (max);
	// max menor que num
	int i = 0;
	min = -1;
	while (i < stack->len)
	{
		if (stack->stack[i] < num && stack->stack[i] > min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int get_num_to_top_a(t_stack *stack, int num) // 2
{
	int max;
	int min;

	max = get_max_num_stack(stack); // 9
	min = get_min_num_stack(stack); // 3
	if (num > max || num < min)
		return (min);

	// max menor que num
	int i = 0;
	min = stack->len + 1;
	while (i < stack->len)
	{
		if (stack->stack[i] > num && stack->stack[i] < min)
			min = stack->stack[i];
		i++;
	}
	return (min);
}

int max(int n1, int n2)
{
	if (n1 > n2)
		return n1;
	return n2;
}

int min(int n1, int n2)
{
	if (n1 > n2)
		return n2;
	return n1;
}

int abs(int n)
{
	if (n < 0)
		return (n * -1);
	return n;
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

t_movements get_moves_order_a(t_stack *stack_a, t_stack *stack_b)
{
	int movs_rotate_a;
	int movs_rotate_b;
	int movs_reverse_a;
	int movs_reverse_b;
	int pos, movs;
	int a, b, c, d;
	t_movements moves;
	int type;

	pos = 0;
	movs = 0;
	moves.ra = 0;
	moves.rb = 0;
	moves.rr = 0;
	moves.rra = 0;
	moves.rrb = 0;
	moves.rrr = 0;
	int i = 0;
	while (i < stack_a->len)
	{
		int obj = stack_a->stack[i];
		movs_rotate_a = get_movs_rotate(stack_a, obj);
		movs_rotate_b = get_movs_rotate(stack_b, get_num_to_top_b(stack_b, obj));
		movs_reverse_a = get_movs_reverse(stack_a, obj);
		movs_reverse_b = get_movs_reverse(stack_b, get_num_to_top_b(stack_b, obj));

		// max_rot + (rot_a - rot_b)
		a = max(movs_rotate_a, movs_rotate_b);
		// if (movs_rotate_a != 0 && movs_rotate_b != 0)
		// 	a += abs(movs_rotate_a - movs_rotate_b);
		// max_rev + (rev_a - rev_b)
		b = max(movs_reverse_a, movs_reverse_b);
		// if (movs_reverse_a != 0 && movs_reverse_b != 0)
		// 	b += abs(movs_reverse_a - movs_reverse_b);
		// rot_a + rev_b
		c = movs_rotate_a + movs_reverse_b;
		// rev_a + rot_a
		d = movs_reverse_a + movs_rotate_b;

		if (i == 0 || min(min(a, b), min(c, d)) < movs)
		{
			movs = min(min(a, b), min(c, d));
			type = get_type(a, b, c, d);
			pos = i;
		}
		// printf("Moves: a: %i, b: %i, c: %i, d: %i\n", a, b, c, d);
		// printf("Moves total: %i, type: %c, pos: %i\n", movs, (type + 'a'), pos);
		i++;
	}
	movs_rotate_a = get_movs_rotate(stack_a, stack_a->stack[pos]);
	movs_rotate_b = get_movs_rotate(stack_b, get_num_to_top_b(stack_b, stack_a->stack[pos]));
	movs_reverse_a = get_movs_reverse(stack_a, stack_a->stack[pos]);
	movs_reverse_b = get_movs_reverse(stack_b, get_num_to_top_b(stack_b, stack_a->stack[pos]));

	if (type == 0)
	{
		moves.rr = min(movs_rotate_a, movs_rotate_b);
		if (movs_rotate_a > movs_rotate_b)
			moves.ra = movs_rotate_a - movs_rotate_b;
		else
			moves.rb = movs_rotate_b - movs_rotate_a;
	}
	else if (type == 1)
	{
		moves.rrr = min(movs_reverse_a, movs_reverse_b);
		if (movs_reverse_a > movs_reverse_b)
			moves.rra = movs_reverse_a - movs_reverse_b;
		else
			moves.rrb = movs_reverse_b - movs_reverse_a;
	}
	else if (type == 2)
	{
		moves.ra = movs_rotate_a;
		moves.rrb = movs_reverse_b;
	}
	else if (type == 3)
	{
		moves.rra = movs_reverse_a;
		moves.rb = movs_rotate_b;
	}
	return (moves);
}
t_movements get_moves_order_b(t_stack *stack_a, t_stack *stack_b)
{
	int movs_rotate_a;
	int movs_rotate_b;
	int movs_reverse_a;
	int movs_reverse_b;
	int pos, movs;
	int a, b, c, d;
	t_movements moves;
	int type;

	int i = 0;
	pos = 0;
	movs = 0;
	moves.ra = 0;
	moves.rb = 0;
	moves.rr = 0;
	moves.rra = 0;
	moves.rrb = 0;
	moves.rrr = 0;
	while (i < stack_a->len)
	{
		movs_rotate_a = get_movs_rotate(stack_a, get_num_to_top_a(stack_a, stack_b->stack[i]));
		movs_rotate_b = get_movs_rotate(stack_b, stack_b->stack[i]);
		movs_reverse_a = get_movs_reverse(stack_a, get_num_to_top_a(stack_a, stack_b->stack[i]));
		movs_reverse_b = get_movs_reverse(stack_b, stack_b->stack[i]);

		// max_rot + (rot_a - rot_b)
		a = max(movs_rotate_a, movs_rotate_b);
		// if (movs_rotate_a != 0 && movs_rotate_b != 0)
		// 	a += abs(movs_rotate_a - movs_rotate_b);
		// max_rev + (rev_a - rev_b)
		b = max(movs_reverse_a, movs_reverse_b);
		// if (movs_reverse_a != 0 && movs_reverse_b != 0)
		// 	b += abs(movs_reverse_a - movs_reverse_b);
		// rot_a + rev_b
		c = movs_rotate_a + movs_reverse_b;
		// rev_a + rot_a
		d = movs_reverse_a + movs_rotate_b;

		if (i == 0 || min(min(a, b), min(c, d)) < movs)
		{
			movs = min(min(a, b), min(c, d));
			type = get_type(a, b, c, d);
			pos = i;
		}
		// printf("Moves: a: %i, b: %i, c: %i, d: %i\n", a, b, c, d);
		// printf("Moves total: %i\n", movs);
		i++;
	}
		movs_rotate_a = get_movs_rotate(stack_a, get_num_to_top_a(stack_a, stack_b->stack[pos]));
		movs_rotate_b = get_movs_rotate(stack_b, stack_b->stack[pos]);
		movs_reverse_a = get_movs_reverse(stack_a, get_num_to_top_a(stack_a, stack_b->stack[pos]));
		movs_reverse_b = get_movs_reverse(stack_b, stack_b->stack[pos]);


	if (type == 0)
	{
		moves.rr = min(movs_rotate_a, movs_rotate_b);
		if (movs_rotate_a > movs_rotate_b)
			moves.ra = movs_rotate_a - movs_rotate_b;
		else
			moves.rb = movs_rotate_b - movs_rotate_a;
	}
	else if (type == 1)
	{
		moves.rrr = min(movs_reverse_a, movs_reverse_b);
		if (movs_reverse_a > movs_reverse_b)
			moves.rra = movs_reverse_a - movs_reverse_b;
		else
			moves.rrb = movs_reverse_b - movs_reverse_a;
	}
	else if (type == 2)
	{
		moves.ra = movs_rotate_a;
		moves.rrb = movs_reverse_b;
	}
	else if (type == 3)
	{
		moves.rra = movs_reverse_a;
		moves.rb = movs_rotate_b;
	}
	return (moves);
}

void printStacks(t_stack *stack_a, t_stack *stack_b)
{
	printf("Stack a: ");
	for (int i = 0; i < stack_a->len; i++)
	{
		printf("%i ", stack_a->stack[i] + 1);
	}
	printf("\n");
	printf("Stack b: ");
	for (int i = 0; i < stack_b->len; i++)
	{
		printf("%i ", stack_b->stack[i] + 1);
	}
	printf("\n");
}

int is_order_stack3(t_stack *stack)
{
	return (
		(stack->stack[0] < stack->stack[1] && stack->stack[1] < stack->stack[2]) || (stack->stack[0] > stack->stack[1] && stack->stack[1] < stack->stack[2]) || (stack->stack[0] < stack->stack[1] && stack->stack[1] > stack->stack[2] && stack->stack[0] > stack->stack[2]));
}

void push_swap(t_stack *stack_a, t_stack *stack_b)
{
	t_movements moves;
	int i;

	int c = 0;
	pb(stack_a, stack_b, 1);
	pb(stack_a, stack_b, 1);
	// printStack(stack_b);
	while (stack_a->len > 3)
	{
		moves = get_moves_order_a(stack_a, stack_b);
		i = 0;
		while (i < moves.ra)
		{
			ra(stack_a, 1);
			i++;
		}
		i = 0;
		while (i < moves.rb)
		{
			rb(stack_b, 1);
			i++;
		}
		i = 0;
		while (i < moves.rr)
		{
			rr(stack_a, stack_b, 1);
			i++;
		}
		i = 0;
		while (i < moves.rra)
		{
			rra(stack_a, 1);
			i++;
		}
		i = 0;
		while (i < moves.rrb)
		{
			rrb(stack_b, 1);
			i++;
		}
		i = 0;
		while (i < moves.rrr)
		{
			rrr(stack_a, stack_b, 1);
			i++;
		}
		pb(stack_a, stack_b, 1);
		// printStacks(stack_a, stack_b);
		c++;
	}

	// stack a esta ordenado
	// stack a esta ordenado al reves
	// stack a no esta ordenado

	if (!is_order_stack3(stack_a))
	{
		sa(stack_a, 1);
	}

	// printStacks(stack_a, stack_b);

	while (stack_b->len > 0)
	{
		moves = get_moves_order_b(stack_a, stack_b);
		i = 0;
		while (i < moves.ra)
		{
			ra(stack_a, 1);
			i++;
		}
		i = 0;
		while (i < moves.rb)
		{
			rb(stack_b, 1);
			i++;
		}
		i = 0;
		while (i < moves.rr)
		{
			rr(stack_a, stack_b, 1);
			i++;
		}
		i = 0;
		while (i < moves.rra)
		{
			rra(stack_a, 1);
			i++;
		}
		i = 0;
		while (i < moves.rrb)
		{
			rrb(stack_b, 1);
			i++;
		}
		i = 0;
		while (i < moves.rrr)
		{
			rrr(stack_a, stack_b, 1);
			i++;
		}
		pa(stack_a, stack_b, 1);
		// printStacks(stack_a, stack_b);
		c++;
	}

	if (get_min_num_stack_position(stack_a) > stack_a->len)
	{
		while (stack_a->stack[0] != 0)
			rra(stack_a, 1);
	}
	else
	{
		while (stack_a->stack[0] != 0)
			ra(stack_a, 1);
	}

	// if (get_max_num_stack_position(stack_b) > stack_b->len)
	// {
	// 	while (stack_b->stack[0] != 0)
	// 		rrb(stack_b, 1);
	// }
	// else
	// {
	// 	while (stack_b->stack[0] != 0)
	// 		rb(stack_b, 1);
	// }

	// while (stack_b->len > 0)
	// {
	// 	pa(stack_a, stack_b, 1);
	// }

	// printStacks(stack_a, stack_b);
}