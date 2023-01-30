/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:34:48 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/24 17:50:36 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "parse.h"
#include "errors.h"

void push_swap(t_stack *stack_a, t_stack *stack_b);
void	get_positions(t_stack *stack);

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	create_stacks(&stack_a, &stack_b, argc - 1);
	if (parse_args(argc, argv, &stack_a) == -1)
		print_error();
	// get_positions(&stack_a);
	push_swap(&stack_a, &stack_b);
	destroy_stacks(&stack_a, &stack_b);
	return (0);
}
