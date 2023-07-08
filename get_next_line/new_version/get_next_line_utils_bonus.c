/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:34:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 12:34:06 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/**
 * @brief Get a copy of string
 * 
 * @param dst 
 * @param src 
 * @param dstsize 
 * @return size_t 
 */
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	unsigned long	d;
	unsigned long	s;

	d = 0;
	s = 0;
	while (src[s] != '\0')
	{
		s++;
	}
	if (dstsize != 0)
	{
		while (d < dstsize - 1 && src[d] != '\0')
		{
			dst[d] = src[d];
			d++;
		}
		dst[d] = '\0';
	}
	return (s);
}

/**
 * @brief Join two string in a new string
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		l_s1;
	int		l_s2;
	int		c;

	l_s1 = ft_strlen((char *)s1, 0);
	l_s2 = ft_strlen((char *)s2, 0);
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

/**
 * @brief Get a new string cuting a string
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_l;
	size_t	l;

	str_l = ft_strlen(s, 0);
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

/**
 * @brief Get len of string or len to end line of string
 * 
 * @param s 
 * @param is_line 
 * @return int 
 */
int	ft_strlen(char *s, int is_line)
{
	int	i;

	i = 0;
	if (is_line)
	{
		while (s[i] != '\n')
			i++;
		return (i + 1);
	}
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * @brief get a flag for know if string have a end line
 * 
 * @param s 
 * @return int 
 */
int	ft_have_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
