/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_toupper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:52:14 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:40:47 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_toupper(void)
{
	char	c;

	c = 'm';
	colors('Y');
	printf("===============\n");
	printf("13. FT_TOUPPER:\n");
	printf("===============\n");
	colors('N');
	printf("%c -> %c", c, toupper(c));
	printf("\n%c -> %c", c, ft_toupper(c));
	c = 'D';
	printf("\n%c -> %c", c, toupper(c));
	printf("\n%c -> %c", c, ft_toupper(c));
	c = '9';
	printf("\n%c -> %c", c, toupper(c));
	printf("\n%c -> %c\n", c, ft_toupper(c));
	return (0);
}
