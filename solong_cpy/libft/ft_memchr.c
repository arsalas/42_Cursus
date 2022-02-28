/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:06:15 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/25 14:56:50 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == ch)
			return (str + i);
		i++;
	}
	return (NULL);
}
