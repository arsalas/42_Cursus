/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:26:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/16 18:49:58 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n)
{
	int	d;

	d = 0;
	if (n < 0)
	{
		d++;
		while (n <= -1)
		{
			n /= 10;
			d++;
		}
	}
	else
	{
		while (n > 0)
		{
			n /= 10;
			d++;
		}
	}
	return (d);
}

static void	transform_number(char *num, int digits, int n)
{
	int	i;

	i = 0;
	num[digits] = '\0';
	if (n < 0)
	{
		num[0] = '-';
		i++;
	}
	while (i < digits)
	{
		if (n < 0)
			num[digits - i] = -(n % 10) + '0';
		else
			num[digits - i - 1] = (n % 10) + '0';
		i++;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*num;

	if (n == 0)
		digits = 1;
	else
		digits = get_digits(n);
	num = malloc(sizeof(char) * (digits + 1));
	if (num == NULL)
		return (NULL);
	transform_number(num, digits, n);
	return (num);
}
