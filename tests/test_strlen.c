/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:29:41 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:38:49 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_strlen(void)
{
	colors('Y');
	printf("===============\n");
	printf("6. FT_STRLEN:\n");
	printf("===============\n");
	colors('N');
	printf("Hola Mundo -> %lu\n", strlen("Hola Mundo"));
	printf("Hola Mundo -> %i\n", ft_strlen("Hola Mundo"));
	return (0);
}
