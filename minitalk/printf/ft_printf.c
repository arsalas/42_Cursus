/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:55:49 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/23 13:08:42 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	selector_type(va_list args, char type)
{
	if (type == 'c')
		return (print_char(va_arg(args, int)));
	else if (type == 's')
		return (print_string(va_arg(args, char *)));
	else if (type == 'p')
		return (print_pointer(va_arg(args, unsigned long long)));
	else if (type == 'd' || type == 'i')
		return (print_number(va_arg(args, int)));
	else if (type == 'u')
		return (print_number_unsgned(va_arg(args, unsigned int)));
	else if (type == 'x')
		return (print_hex(va_arg(args, unsigned int), 0));
	else if (type == 'X')
		return (print_hex(va_arg(args, unsigned int), 1));
	else if (type == '%')
		return (print_char('%'));
	else
		return (0);
}

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
