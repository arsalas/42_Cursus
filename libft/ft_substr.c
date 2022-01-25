/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 19:38:30 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/21 13:54:03 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_l;
	size_t	l;

	str_l = ft_strlen(s);
	if (str_l - start >= len)
		l = len + 1;
	else
		l = str_l - start + 1;
	if (len == 0 || str_l == 0 || start > str_l)
	{
		str = malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * l);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (s + start), l);
	return (str);
}
