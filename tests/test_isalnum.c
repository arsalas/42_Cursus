/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isalnum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:29:41 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:33:44 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_isalnum(void)
{
	colors('Y');
	printf("===============\n");
	printf("3. FT_ISALNUM:\n");
	printf("===============\n");
	colors('N');
	printf("1 -> %i\n", isalnum('1'));
	printf("1 -> %i\n", ft_isalnum('1'));
	printf("a -> %i\n", isalnum('a'));
	printf("a -> %i\n", ft_isalnum('a'));
	printf("~ -> %i\n", isalnum('~'));
	printf("~ -> %i\n", ft_isalnum('~'));
	return (0);
}
