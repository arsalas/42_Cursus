/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:38:07 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/08 16:26:26 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(const char *str, ...);

int	main(void)
{
	char	p;

	p = 10;
	ft_printf("Pintando dos letras: %c %c\n", 'a', 'b');
	printf("Pintando dos letras: %c %c\n", 'a', 'b');
	ft_printf("Pintando un string: %s\n", "Hola Mundo");
	printf("Pintando un string: %s\n", "Hola Mundo");
	ft_printf("Pintando un puntero: %p\n", &p);
	printf("Pintando un puntero: %p\n", &p);
	ft_printf("Pintando un numero decimal: %d\n", 133);
	printf("Pintando un numero decimal: %d\n", 133);
	ft_printf("Pintando un numero entero: %i\n", 133);
	printf("Pintando un numero entero: %i\n", 133);
	ft_printf("Pintando un numero unsigned: %i\n", -1);
	printf("Pintando un numero unsigned: %i\n", -1);
	ft_printf("Pintando un numero hexadecimal: %x\n", 7000);
	printf("Pintando un numero hexadecimal: %x\n", 7000);
	ft_printf("Pintando un numero hexadecimal: %X\n", 7000);
	printf("Pintando un numero hexadecimal: %X\n", 7000);
	return (0);
}
