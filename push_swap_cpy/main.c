/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:34:48 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/24 12:46:28 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_smallest(int *stack)
{
	int	i;

	i = 1;
	while (stack[i])
	{
		if (stack[0] > stack[i])
			return (0);
		i++;
	}
	return (1);
}

static void	order_array(int *stack_a, int *stack_b)
{
	if (is_order(stack_a) == 1 && get_len(stack_b) == 0)
		return ;
	if (is_order(stack_a) == 1 && get_len(stack_b) > 0)
	{
		while (get_len(stack_b) > 0)
			pa(stack_a, stack_b);
	}
	else
	{
		if (stack_a[1] < stack_a[0])
			sa(stack_a);
		else if (stack_a[get_len(stack_a) - 1] < stack_a[0])
			ra(stack_a);
		else if (is_smallest(stack_a) == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		order_array(stack_a, stack_b);
	}
}

int	main(int argc, char *argv[])
{
	int	*stack_a;
	int	*stack_b;

	stack_a = ft_calloc(sizeof(int), argc);
	if (stack_a == NULL)
		return (0);
	stack_b = ft_calloc(sizeof(int), argc);
	if (stack_b == NULL)
	{
		free(stack_a);
		return (0);
	}
	if (do_format(argc, argv, stack_a) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	order_array(stack_a, stack_b);
	return (0);
}
