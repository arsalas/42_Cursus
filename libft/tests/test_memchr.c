/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_memchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:01:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:36:06 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_memchr(void)
{
	const char	str[] = "http://www.tutorialspoint.com";
	const char	ch = '.';
	char		*ret;
	const char	str2[] = "http://www.tutorialspoint.com";
	const char	ch2 = '.';
	char		*ret2;
	colors('Y');
	printf("===============\n");
	printf("18. FT_MEMCHR:\n");
	printf("===============\n");
	colors('N');
	ret = memchr(str, ch, 1);
	printf("String after |%c| is - |%s|\n", ch, ret);
	ret2 = ft_memchr(str2, ch2, 1);
	printf("String after |%c| is - |%s|\n", ch2, ret2);
	return (0);
}
