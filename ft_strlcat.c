/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:18:16 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/10 18:52:56 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	int	i;
	int	j;

	i = 0;
	while (dst[i] != '\0')
	{
		i++;
	}
	j = 0;
	while ((dstsize) > (j + i - 1) && src[j] != '\0')
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	return (dstsize);
}
