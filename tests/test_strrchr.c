/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strrchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:29:25 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:40:04 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_strrchr(void)
{
	int			len;
	const char	str[] = "http://www.tutorialspoint.com";
	const char	ch = '.';
	char		*ret;
	const char	str2[] = "http://www.tutorialspoint.com";
	const char	ch2 = '.';
	char		*ret2;
	colors('Y');
	printf("===============\n");
	printf("16. FT_STRRCHR:\n");
	printf("===============\n");
	colors('N');
	ret = strrchr(str, ch);
	printf("String after |%c| is - |%s|\n", ch, ret);
	ret2 = ft_strrchr(str2, ch2);
	printf("String after |%c| is - |%s|\n", ch2, ret2);
	return (0);
}
