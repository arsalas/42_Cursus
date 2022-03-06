/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:47:45 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/23 13:07:04 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	print_hex(unsigned long num, int upper);
int	print_number(long num);
int	print_number_unsgned(unsigned int num);
int	print_string(char *str);
int	print_pointer(unsigned long long p);
int	print_char(char c);
#endif
