/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:23:05 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/08 12:10:29 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	contain_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	get_storage_len(char *storage)
{
	if (storage)
		return (get_len(storage));
	else
		return (0);
}

char	*concat_str(char *storage, char *buffer, int len_b)
{
	int		i;
	int		len_s;
	char	*str;

	len_s = get_storage_len(storage);
	str = malloc(sizeof(char) * (len_s + len_b + 1));
	if (str == NULL)
		return (free_malloc(storage));
	i = 0;
	while (i < len_s)
	{
		str[i] = storage[i];
		i++;
	}
	i = 0;
	while (i < len_b)
	{
		str[len_s + i] = buffer[i];
		i++;
	}
	str[len_s + i] = '\0';
	free(storage);
	return (str);
}

int	count_line_words(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
		i++;
	return (i + 1);
}
