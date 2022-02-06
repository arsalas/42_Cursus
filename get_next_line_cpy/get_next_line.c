/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:14:42 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/04 17:25:59 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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

char	*concat_str(char *storage, char *buffer)
{
	int		i;
	int		len_s;
	int		len_b;
	char	*str;

	if (storage)
		len_s = get_len(storage);
	else
		len_s = 0;
	len_b = get_len(buffer);
	str = malloc(sizeof(char) * (len_s + len_b + 1));
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
	free(buffer);
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

void	clean_storage(char *storage)
{
	int		old_len;
	int		new_len;
	int		i;

	old_len = count_line_words(storage);
	new_len = get_len(storage) - old_len;
	i = 0;
	while (i < new_len)
	{
		storage[i] = storage[old_len + i];
		i++;
	}
	storage[i] = '\0';
}

char	*extract_line(char *str)
{
	int		words;
	int		i;
	char	*line;

	words = count_line_words(str);
	line = malloc(sizeof(char) * (words + 1));
	i = 0;
	while (i < words)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	clean_storage(str);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*storage;
	int			numbytes;

	if (storage && contain_line(storage) == 1)
	{
		return(extract_line(storage));
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	numbytes = read(fd, buffer, BUFFER_SIZE);
	buffer[BUFFER_SIZE] = '\0';
	storage = concat_str(storage, buffer);
	return (get_next_line(fd));
}
