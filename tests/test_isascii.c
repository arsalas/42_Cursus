/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isascii.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:29:41 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:34:39 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_isascii(void)
{
	colors('Y');
	printf("===============\n");
	printf("4. FT_ISASCII:\n");
	printf("===============\n");
	printf("a -> %i\n", isascii('a'));
	printf("a -> %i\n", ft_isascii('a'));
	return (0);
}
