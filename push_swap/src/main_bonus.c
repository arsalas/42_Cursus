/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:34:48 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/24 13:32:42 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;
	char	str[10];
	int		nb;

	create_stacks(&stack_a, &stack_b, argc - 1);
	if (do_format(argc, argv, &stack_a) == 1)
		print_error();
	get_positions(&stack_a);
	nb = 1;
	while (nb > 0)
	{
		nb = read(1, str, 1000);
		if (nb > 0)
		{
			str[nb] = '\0';
			actions(str, &stack_a, &stack_b);
		}
	}
	if (is_order(&stack_a) == 1 && stack_b.len == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	destroy_stacks(&stack_a, &stack_b);
	return (0);
}
