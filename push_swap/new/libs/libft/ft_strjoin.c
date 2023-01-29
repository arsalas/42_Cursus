/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:32:16 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/19 11:56:16 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		l_s1;
	int		l_s2;
	int		c;

	l_s1 = ft_strlen((char *)s1);
	l_s2 = ft_strlen((char *)s2);
	str = malloc(sizeof(char) * (l_s1 + l_s2 + 1));
	if (str == NULL)
		return (NULL);
	c = 0;
	while (c < l_s2 || c < l_s1)
	{
		if (c < l_s1)
			str[c] = s1[c];
		if (c < l_s2)
			str[l_s1 + c] = s2[c];
		c++;
	}
	str[l_s1 + l_s2] = '\0';
	return (str);
}
