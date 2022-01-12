/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strlcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:20:25 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:38:17 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_strlcpy(void)
{
	char	*str = "Hola Mundo";
	char	dst[10];
	char	*str2 = "Hola Mundo";
	char	dst2[10];
	colors('Y');
	printf("===============\n");
	printf("11. FT_ISALNUM:\n");
	printf("===============\n");
	colors('N');
	strlcpy(dst, str, 3);
	ft_strlcpy(dst2, str2, 3);
	printf("%s\n", dst);
	printf("%s\n", dst2);
	return (0);
}
