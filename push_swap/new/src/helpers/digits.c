/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 16:25:54 by aramirez          #+#    #+#             */
/*   Updated: 2022/05/20 18:44:37 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Obtiene cutos digitos tiene un numero 
 * 
 * @param num numero
 * @return cantidad de digitos del numero 
 */
int	get_digits(int num)
{
	int	i;

	i = 0;
	if (num < 0)
		num = -num;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		i++;
		num /= 10;
	}
	return (i);
}

/**
 * @brief Obtiene el digito pedido de un numero
 * 
 * @param num numero
 * @param d digito a buscar
 * @return valor del digito buscado
 */
int	get_digit(int num, int d)
{
	int	sub;
	int	sign;

	sign = 1;
	if (num < 0 && d == get_digits(num))
		sign = -1;
	if (num < 0)
		num = -num;
	sub = d - 1;
	while (sub > 0)
	{
		num /= 10;
		sub--;
	}
	return (num % 10 * sign);
}
