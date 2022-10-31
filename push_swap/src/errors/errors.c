/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 15:54:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/23 14:26:10 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Printa error en pantalla
 * 
 */
void	print_error(void)
{
	write(1, "Error\n", 6);
	exit(0);
}

/**
 * @brief Comprueba si es un numero valido 
 * 
 * @param num numero a comprobar
 * @return 1 si es valido 0 si no lo es
 */
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

/**
 * @brief Comprueba si el numero pasado como string es superior a un int
 * 
 * @param str string del numero a comprobar
 * @return 1 si es valido 0 si no lo es
 */
int	is_long(const char *str)
{
	int			i;
	long long	n;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((unsigned char)str[i] == ' ' || (unsigned char)str[i] == '\t'
		|| (unsigned char)str[i] == '\n' || (unsigned char)str[i] == '\f'
		|| (unsigned char)str[i] == '\r' || (unsigned char)str[i] == '\v')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	n *= sign;
	if (n > INT_MAX || n < INT_MIN)
		return (1);
	else
		return (0);
}

/**
 * @brief Buscar si el numero esta repetido
 * 
 * @param num numero a comprobar
 * @param stack stack a buscar
 * @return 1 si esta duplicado 0 si no lo esta 
 */
int	is_duplicate(int num, t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->len)
	{
		if (stack->original[i] == num)
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Comprueba si los strings pasados son numeros y los convierte a int
 * 
 * @param argc contador de argumentos
 * @param argv valor de argumentos
 * @param stack stack
 * @return 1 si hay algun error y 0 si no hay errores 
 */
int	do_format(int argc, char *argv[], t_stack *stack)
{
	int	i;
	int	num;

	i = 0;
	if (argc == 1)
		exit(0);
	while (i < argc - 1)
	{
		if (ft_isnumbervalid((argv[i + 1])) == 0)
			return (1);
		num = ft_atoi(argv[i + 1]);
		if ((is_duplicate(num, stack) == 1 || is_long(argv[i + 1]) == 1))
			return (1);
		stack->original[i] = ft_atoi(argv[i + 1]);
		stack->len++;
		i++;
	}
	return (0);
}
