/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:20:23 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/18 16:46:21 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;
	int		f;
	int		find;

	p = (char *)s;
	i = 0;
	f = 0;
	find = 0;
	if ((unsigned char)c == '\0')
		return (p + ft_strlen(p));
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
		{
			f = i;
			find = 1;
		}
		i++;
	}
	if (find == 1)
		return (p + f);
	else
		return (0);
}
