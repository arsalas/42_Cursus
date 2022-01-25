/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:27:17 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/21 12:55:09 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_searchstr(char *str1, const char *str2, size_t i, size_t len)
{
	size_t	j;
	int		find;

	j = 0;
	find = 1;
	while (str2[j] != '\0')
	{
		if (str1[i + j] != str2[j])
			find = 0;
		j++;
	}
	if ((i + j) > len)
		find = 0;
	return (find);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	size_t	i;
	int		f;

	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	str = (char *)haystack;
	i = 0;
	f = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			f = ft_searchstr(str, needle, i, len);
			if (f == 1)
				break ;
		}
		i++;
	}
	if (f == 1)
		return (str + i);
	else
		return (NULL);
}
