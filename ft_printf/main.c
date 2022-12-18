/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:38:07 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/22 16:51:05 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int	main(void)
{
	void	*p;

	printf("\x1B[32m");
	printf("╔══════════════════════════════════════════════════════════════╗\n");
	printf("║                      🚀 FT_PRINTF 🚀                         ║\n");
	printf("╚══════════════════════════════════════════════════════════════╝\n");
	printf("\x1B[37m\n");
	printf(" | RETURN: %i\n", ft_printf("M_PRINTF: NO PRAMS"));
	printf(" | RETURN: %i\n", printf("O_PRINTF: NO PRAMS"));
	printf(" | RETURN: %i\n", ft_printf("M_PRINTF: inex %j"));
	printf(" | RETURN: %i\n", printf("O_PRINTF: inex %j"));
	printf(" | RETURN: %i\n", ft_printf("M_PRINTF(caracter): %c %c", 'a', 'b'));
	printf(" | RETURN: %i\n", printf("O_PRINTF(caracter): %c %c", 'a', 'b'));
	printf(" | RETURN: %i\n", ft_printf("M_PRINTF(string): %s", "Hola\n mundo"));
	printf(" | RETURN: %i\n", printf("O_PRINTF(string): %s", "Hola\n mundo"));
	printf(" | RETURN: %i\n", ft_printf("M_PRINTF(string NULL): %s", NULL));
	printf(" | RETURN: %i\n", printf("O_PRINTF(string NULL): %s", NULL));
	printf(" | RETURN: %i\n", ft_printf("M_PRINTF(puntero): %p", p));
	printf(" | RETURN: %i\n", printf("O_PRINTF(puntero): %p", p));
	printf(" | RETURN: %i\n", ft_printf("M_PRINTF(decimal): %d", 0133));
	printf(" | RETURN: %i\n", printf("O_PRINTF(decimal): %d", 0133));
	printf(" | RETURN: %i\n", ft_printf("M_PRINTF(entero): %i", -2147483647));
	printf(" | RETURN: %i\n", printf("O_PRINTF(entero): %i", -2147483647));
	printf(" | RETURN: %i\n", ft_printf("M_PRINTF(unsigned): %u", -1));
	printf(" | RETURN: %i\n", printf("O_PRINTF(unsigned): %u", -1));
	printf(" | RETURN: %i\n", ft_printf("M_PRINTF(hexadecmal min): %x", -7000));
	printf(" | RETURN: %i\n", printf("O_PRINTF(hexadecmal min): %x", -7000));
	printf(" | RETURN: %i\n", ft_printf("M_PRINTF(hexadecmal may): %X", 7000));
	printf(" | RETURN: %i\n", printf("O_PRINTF(hexadecmal may): %X", 7000));
	printf(" | RETURN: %i\n", ft_printf("M_PRINTF(porcentaje): %%"));
	printf(" | RETURN: %i\n", printf("O_PRINTF(porcentaje): %%"));
	printf(" | RETURN: %i\n", ft_printf("M_PRINTF: %s + i: %i, i: %i", "texto", 10, 20));
	printf(" | RETURN: %i\n", printf("O_PRINTF: %s + i: %i, i: %i", "texto", 10, 20));
	return (0);
}
