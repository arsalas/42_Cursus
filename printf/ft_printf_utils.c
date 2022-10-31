/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:20:50 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/04 15:30:16 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long num, int upper)
{
	int	numbytes;

	numbytes = 0;
	if (num >= 16)
	{
		numbytes += print_hex(num / 16, upper);
		num %= 16;
	}
	if (num < 16)
	{
		if (num < 10)
			print_char(num + '0');
		else
		{
			if (upper == 1)
				print_char((num - 10 + 'A'));
			else
				print_char((num - 10 + 'a'));
		}
		numbytes++;
	}
	return (numbytes);
}

int	print_number(long num)
{
	int	numbytes;

	numbytes = 0;
	if (num < 0)
	{
		print_char('-');
		num = -num;
		numbytes++;
	}
	if (num >= 10)
	{
		numbytes += print_number(num / 10);
		num %= 10;
	}
	if (num < 10)
	{
		print_char(num + '0');
		numbytes++;
	}
	return (numbytes);
}

int	print_number_unsgned(unsigned int num)
{
	int	numbytes;

	if (num < 0)
	{
		print_char('-');
		num = -num;
	}
	numbytes = 0;
	if (num >= 10)
	{
		numbytes += print_number(num / 10);
		num %= 10;
	}
	if (num < 10)
	{
		print_char(num + '0');
		numbytes++;
	}
	return (numbytes);
}

int	print_string(char *str)
{
	int	i;

	if (str == NULL)
		return (print_string("(null)"));
	i = 0;
	while (str[i])
	{
		print_char(str[i]);
		i++;
	}
	return (i);
}

int	print_pointer(unsigned long long p)
{
	return (print_string("0x") + print_hex(p, 0));
}
