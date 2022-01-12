/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strnstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:27:07 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:39:41 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_strnstr(void)
{
	const char	*largestring = "Foo Bar Baz";
	const char	*smallstring = "Bar";
	const char	*largestring2 = "Foo Bar Baz";
	const char	*smallstring2 = "Bar";
	char		*ptr;
	char		*ptr2;
	colors('Y');
	printf("===============\n");
	printf("20. FT_MEMCHR:\n");
	printf("===============\n");
	colors('N');
	ptr = strnstr(largestring, smallstring, 4);
	ptr2 = ft_strnstr(largestring2, smallstring2, 4);
	printf("%s\n", ptr);
	printf("%s\n", ptr2);
	return (0);
}
