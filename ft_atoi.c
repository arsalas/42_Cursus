/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:11:58 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/11 15:01:38 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_increment(const char *str, int num, int i)
{
	if (str[i] == '0')
		num *= 10;
	else
	{
		if (num % 10 == 0)
			num = num * 10 + (str[i] - '0');
		else
			num = (num / 10 + (num % 10 * 10)) + (str[i] - '0');
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	int		num;
	int		i;
	int		sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] >= 0 && str[i] <= 31)
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = ft_increment(str, num, i);
		i++;
	}
	return (sign * num);
}
