/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:06:09 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/17 17:06:15 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;

	i = 0;
	while (((unsigned char)s1[i] == (unsigned char)s2[i])
		&& (unsigned char)s1[i] != '\0'
		&& (unsigned char)s2[i] != '\0'
		&& i < n)
	{
		i++;
	}
	if (n == 0)
		return (0);
	if (n == i)
		return (((unsigned char)s1[i - 1] - (unsigned char)s2[i - 1]));
	return (((unsigned char)s1[i] - (unsigned char)s2[i]));
}
