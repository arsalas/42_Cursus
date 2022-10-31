/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
<<<<<<<< HEAD:cpp_4/ex01/Brain.hpp
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:32:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/21 16:30:45 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Brain_H
#define Brain_H
#include <iostream>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain(void);
	~Brain(void);
};

#endif
========
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:34:48 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/24 17:50:36 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	stack_a;
	t_stack	stack_b;

	create_stacks(&stack_a, &stack_b, argc - 1);
	if (do_format(argc, argv, &stack_a) == 1)
		print_error();
	get_positions(&stack_a);
	if (stack_a.len <= 5)
		order_radial(&stack_a, &stack_b, 1);
	else
		chunk_sort(&stack_a, &stack_b);
	destroy_stacks(&stack_a, &stack_b);
	return (0);
}
>>>>>>>> 8ce7687 (update):push_swap/src/main.c
