/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:51:58 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/11 11:57:09 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		i;
	char	*c1;
	char	*c2;

	c1 = (char *)s1;
	c2 = (char *)s2;
	i = 0;
	while ((c1[i] == c2[i]) || c1[i] != '\0' || c2[i] != '\0' || i < n)
	{
		i++;
	}
	return (c1[i] - c2[i]);
}
