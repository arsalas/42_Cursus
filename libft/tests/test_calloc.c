/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:13:20 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:33:13 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"
#include "./tlibft.h"

int	test_calloc(void)
{
	long	*buffer;
	colors('Y');
	printf("===============\n");
	printf("22. FT_CALLOC:\n");
	printf("===============\n");
	colors('N');
	buffer = (long *)ft_calloc(40, sizeof(long));
	if (buffer != NULL)
		printf("Allocated 40 long integers\n");
	else
		printf("Can't allocate memory\n");
	free(buffer);
	return (0);
}