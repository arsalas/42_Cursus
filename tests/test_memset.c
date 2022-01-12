/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 12:07:15 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:37:16 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_memset(void)
{
	char	str[50];
	char	str2[50];
	colors('Y');
	printf("===============\n");
	printf("7. FT_MEMSET:\n");
	printf("===============\n");
	colors('N');
	strcpy(str, "This is string.h library function");
	strcpy(str2, "This is string.h library function");
	puts(str);
	memset(str, '$',7);
	ft_memset(str2, '$',7);
	puts(str);
	puts(str2);
	return (0);
}
