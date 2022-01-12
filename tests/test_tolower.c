/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_tolower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:52:14 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:41:29 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_tolower(void)
{
	char	c;

	c = 'm';
	colors('Y');
	printf("===============\n");
	printf("14. FT_TOLOWER:\n");
	printf("===============\n");
	colors('N');
	printf("%c -> %c", c, tolower(c));
	printf("\n%c -> %c", c, ft_tolower(c));
	c = 'D';
	printf("\n%c -> %c", c, tolower(c));
	printf("\n%c -> %c", c, ft_tolower(c));
	c = '9';
	printf("\n%c -> %c", c, tolower(c));
	printf("\n%c -> %c\n", c, ft_tolower(c));
	return (0);
}
