/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:20:25 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:37:58 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_strlcat(void)
{
	char src[50], dest[50];
	colors('Y');
	printf("===============\n");
	printf("12. FT_STRLCAT:\n");
	printf("===============\n");
	colors('N');
	strcpy(src,  "123456789");
	strcpy(dest, "abc");
	ft_strlcat(dest, src, 7);
	printf("Final destination string : |%s|\n", dest);
	return(0);
}
