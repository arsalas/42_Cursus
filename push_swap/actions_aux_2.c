/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_aux_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:53:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/24 12:17:15 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse(int *stack)
{
	int	len;
	int	i;
	int	aux;

	len = get_len(stack);
	aux = stack[len - 1];
	i = 0;
	while (i < len)
	{
		stack[len - i] = stack[len - 1 - i];
		i++;
	}
	stack[0] = aux;
	stack[len] = '\0';
}

int	is_order(int *stack)
{
	int	i;

	i = 0;
	while (stack[i + 1])
	{
		if (stack[i] > stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

/* 
Buscar si el numero esta repetido o si no es un numero valido 
o si es superion a un int
*/
int	is_duplicate(int num, int *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnumbervalid(char *num)
{
	int	i;

	i = 0;
	if (num[i] == '-')
		i++;
	while (num[i])
	{
		if (ft_isdigit(num[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	do_format(int argc, char *argv[], int *stack)
{
	int	i;
	int	num;

	i = 0;
	while (i < argc - 1)
	{
		if (ft_isnumbervalid((argv[i + 1])) == 0)
			return (1);
		num = ft_atoi(argv[i + 1]);
		if (is_duplicate(num, stack) == 1 || is_long(argv[i + 1]) == 1)
			return (1);
		stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (0);
}
