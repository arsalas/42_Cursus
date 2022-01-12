/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:17:15 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/11 15:32:00 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	int	i;

	i = 0;
	while ((dstsize - 1) > 0 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
		dstsize--;
	}
	return (dstsize);
}
