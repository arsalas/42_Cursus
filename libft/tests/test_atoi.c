/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 13:12:04 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:31:56 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_atoi(void)
{
	char	str[20];
	colors('Y');
	printf("===============\n");
	printf("21. FT_ATOI:\n");
	printf("===============\n");
	colors('N');
	strcpy(str, "\t-901j6");
	printf("String value = %s, Int value = %d\n", str, atoi(str));
	printf("String value = %s, Int value = %d\n", str, ft_atoi(str));
	return (0);
}
