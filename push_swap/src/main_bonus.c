/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:34:48 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/09 17:17:37 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "errors.h"
#include "parse.h"
#include "stack.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	create_stacks(&stack_a, &stack_b, argc - 1);
	if (parse_args(argc, argv, &stack_a) == -1)
		print_error();
	checker(&stack_a, &stack_b);
	destroy_stacks(&stack_a, &stack_b);
	return (0);
}
