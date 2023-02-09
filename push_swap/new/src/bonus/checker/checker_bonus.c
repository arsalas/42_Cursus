/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:35:33 by aramirez          #+#    #+#             */
/*   Updated: 2023/02/09 19:19:41 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "stack_bonus.h"
#include "utils_bonus.h"

void	checker(t_stack *stack_a, t_stack *stack_b)
{
	char	str[1000];
	int		nb;

	nb = 1;
	while (nb > 0)
	{
		nb = read(1, str, 1000);
		if (nb > 0)
		{
			str[nb] = '\0';
			actions(str, stack_a, stack_b);
		}
	}
	if (is_stack_sort(stack_a) == 1 && stack_b->len == 0)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}
