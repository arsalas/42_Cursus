/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strncmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:48:09 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:42:14 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_strncmp(void)
{
	char	str1[20];
	char	str2[20];
	int		result;
	colors('Y');
	printf("===============\n");
	printf("17. FT_STRNCMP:\n");
	printf("===============\n");
	colors('N');
	strcpy(str1, "hello");
	strcpy(str2, "helLO WORLD");
	result = strncmp(str1, str2, 4);
	printf("%i", result);
	result = strncmp(str1, str2, 4);
	printf("\n%i\n", result);
	return (0);
}
