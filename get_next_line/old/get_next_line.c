/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:14:42 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/08 12:21:02 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_malloc(char *str)
{
	free(str);
	return (NULL);
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
	while (i < old_len)
	{
		storage[i] = '\0';
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
	if (line == NULL)
	{
		free(str);
		return (NULL);
	}
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

char	*extract_last_line(char *str, int numbytes, char *buffer)
{
	int		words;
	int		i;
	char	*line;

	free(buffer);
	if (str == NULL || numbytes == -1)
		return (free_malloc(str));
	if (str[0] == '\0')
		return (free_malloc(str));
	words = get_len(str);
	line = malloc(sizeof(char) * (words + 1));
	if (line == NULL)
		return (free_malloc(str));
	i = 0;
	while (i < words)
	{
		line[i] = str[i];
		str[i] = '\0';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*storage;
	int			numbytes;

	if (fd == -1 || fd >= 1000)
		return (NULL);
	if (storage && contain_line(storage) == 1)
		return (extract_line(storage));
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free_malloc(storage));
	numbytes = read(fd, buffer, BUFFER_SIZE);
	if (numbytes == 0 || numbytes == -1)
		return (extract_last_line(storage, numbytes, buffer));
	buffer[BUFFER_SIZE] = '\0';
	storage = concat_str(storage, buffer, numbytes);
	free(buffer);
	buffer = NULL;
	if (storage == NULL)
		return (NULL);
	return (get_next_line(fd));
}
