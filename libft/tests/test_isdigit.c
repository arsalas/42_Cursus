/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_isdigit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:29:41 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:35:04 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_isdigit(void)
{
	colors('Y');
	printf("===============\n");
	printf("2. FT_ISDIGIT:\n");
	printf("===============\n");
	colors('N');
	printf("1 -> %i\n", isdigit('1'));
	printf("1 -> %i\n", ft_isdigit('1'));
	printf("h -> %i\n", isdigit('h'));
	printf("h -> %i\n", ft_isdigit('h'));
	return (0);
}
