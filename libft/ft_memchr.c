/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:06:15 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/18 16:42:57 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char			*str;
	size_t			i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = 0;
	str = (char *)s;
	while ((unsigned char)str[i] != ch && i < n)
	{
		i++;
	}
	if (n == 0)
		return (NULL);
	if (i < n && (unsigned char)str[i] == ch)
		return (str + i);
	return (NULL);
}
