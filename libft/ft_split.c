/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:22:26 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/25 12:37:02 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	words_count(char *s, char c)
{
	int		words;
	char	last_char;
	int		i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if ((last_char == c || !last_char) && s[i] != c)
		{
			words++;
		}
		last_char = s[i];
		i++;
	}
	return (words);
}

char	*extract_word(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	ft_memmove(str, s, i);
	str[i] = '\0';
	return (str);
}

void	free_arr(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*move_pointer(char *str, char c, int i)
{
	if (i == 0)
	{
		while (*str == c && *str)
			str++;
		return (str);
	}
	else
	{
		while (*str != c && *str)
			str++;
		return (move_pointer(str, c, 0));
	}
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	*str;
	int		words;
	int		i;
	char	*res;

	str = (char *)s;
	words = words_count(str, c);
	arr = ft_calloc(sizeof(char *), (words + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	str = move_pointer(str, c, 0);
	while (i < words)
	{
		res = extract_word(str, c);
		if (res == NULL)
		{
			free_arr(arr, i);
			return (NULL);
		}
		arr[i++] = res;
		str = move_pointer(str, c, 1);
	}
	return (arr);
}
