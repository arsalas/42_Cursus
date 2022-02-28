/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:18:16 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/26 19:17:28 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	slen;

	i = 0;
	slen = 0;
	while (*dst != '\0')
	{
		i++;
		dst++;
	}
	if (dstsize > i)
	{
		slen = ft_strlcpy(dst, src, (dstsize - i));
		return (i + slen);
	}
	return (dstsize + ft_strlen((char *)src));
}
