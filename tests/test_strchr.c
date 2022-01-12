/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strchr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:15:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:41:46 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_strchr (void) {
	const char	str[] = "This is just a String";
	const char	ch = 'u';
	char	*p;
	const char	str2[] = "This is just a String";
	const char	ch2 = 'u';
	char	*p2;
	colors('Y');
	printf("===============\n");
	printf("15. FT_STRCHR:\n");
	printf("===============\n");
	colors('N');
	p = strchr(str, ch);
	p2 = ft_strchr(str2, ch2);
	printf("String starting from %c is: %s", ch, p);
	printf("\nString starting from %c is: %s\n", ch2, p2);
	return (0);
}