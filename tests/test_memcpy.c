/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:41:18 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:36:33 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_memcpy(void)
{
	char	str[50];
	char	dst[50];
	char	str2[50];
	char	dst2[50];

	colors('Y');
	printf("===============\n");
	printf("9. FT_MEMCPY:\n");
	printf("===============\n");
	colors('N');
	strcpy(str, "This is string.h library function");
	strcpy(dst, "aaaaaaaaaa");
	strcpy(str2, "This is string.h library function");
	strcpy(dst2, "aaaaaaaaaa");
	memcpy(dst, str, 7);
	ft_memcpy(dst2, str2, 7);
	puts(str);
	puts(dst);
	puts(str2);
	puts(dst2);
	return (0);
}
