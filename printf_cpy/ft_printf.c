/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:55:49 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/08 16:27:24 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_hex(long num, int upper)
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

int	print_number(int num)
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

int	pint_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		print_char(str[i]);
		i++;
	}
	return (i);
}

int	print_pointer(long p)
{
	return (pint_string("0x") + print_hex(p, 0));
}

int	selector_type(va_list args, char type)
{
	if (type == 'c')
		return (print_char(va_arg(args, int)));
	else if (type == 's')
		return (pint_string(va_arg(args, char *)));
	else if (type == 'p')
		return (print_pointer(va_arg(args, long)));
	else if (type == 'd' || type == 'i')
		return (print_number(va_arg(args, int)));
	else if (type == 'u')
		return (print_number(va_arg(args, unsigned int)));
	else if (type == 'x')
		return (print_hex(va_arg(args, long), 0));
	else if (type == 'X')
		return (print_hex(va_arg(args, long), 1));
	else if (type == '%')
		return (print_char('%'));
	else
		return (0);
}

/*
 convertir la direccion de memoria a long y imprimir en hexadecimal 
 (size (void)*)?
*/
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		numprint;
	int		i;

	va_start(args, str);
	numprint = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			numprint += selector_type(args, str[i]);
		}
		else
			numprint += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (numprint);
}
