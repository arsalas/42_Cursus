/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 12:27:17 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/11 17:16:46 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_searchstr(char *str1, const char *str2, int i)
{
	int	j;
	int	find;

	j = 0;
	find = 1;
	while (str2[j] != '\0' )
	{
		if (str1[i + j] != str2[j])
			find = 0;
		j++;
	}
	return (find);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*str;
	int		i;
	int		f;

	str = (char *)haystack;
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			f = ft_searchstr(str, needle, i);
			if (f == 1)
				break ;
		}
		i++;
	}
	if (f == 1)
	{
		while (i-- > 0)
			str++;
		return (str);
	}
	else
		return (NULL);
}
