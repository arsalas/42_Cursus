/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:03:26 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/04 20:56:15 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (i < (int)n && (unsigned char)str1[i] == (unsigned char)str2[i])
	{
		i++;
	}
	if (n == 0)
		return (0);
	if (i < (int)n)
		i++;
	if ((unsigned char)str1[i - 1] == (unsigned char)str2[i - 1])
		return (0);
	else
		return ((unsigned char)str1[i - 1] - (unsigned char)str2[i - 1]);
}
