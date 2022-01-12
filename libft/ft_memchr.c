/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:06:15 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/11 12:15:12 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)s;
	while (*str != c && i < n)
	{
		str++;
		i++;
	}
	if (*str == c)
		return (str);
	else
		return (NULL);
}
