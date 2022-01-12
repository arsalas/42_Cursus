/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:29:41 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:34:24 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_isalpha(void)
{
	colors('Y');
	printf("===============\n");
	printf("1. FT_ISALPHA:\n");
	printf("===============\n");
	colors('N');
	printf("a -> %i\n", isalpha('a'));
	printf("a -> %i\n", ft_isalpha('a'));
	printf("1 -> %i\n", isalpha('1'));
	printf("1 -> %i\n", ft_isalpha('1'));
	return (0);
}
