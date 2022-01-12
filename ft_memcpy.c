/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:06:42 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/10 16:44:53 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	while (n > 0)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dst);
}
