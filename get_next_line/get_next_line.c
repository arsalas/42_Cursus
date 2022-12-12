/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:35:04 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 11:25:06 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

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

t_line	get_line(char *line)
{
	int			len;
	char		*leftover;
	char		*aux;
	t_line		result;

	len = ft_strlen_line(line);
	result.line = ft_substr(line, 0, len);
	leftover = ft_substr(line, len, ft_strlen(line));
	if (!result.line || !leftover)
	{
		result.line = NULL;
		return (result);
	}
	free(line);
	result.storage = leftover;
	return (result);
}

char	*get_empty_line(void)
{
	char	*line;

	line = malloc(sizeof(char));
	line[0] = '\0';
	return (line);
}

t_line	read_file(int fd, char *line)
{
	int		nb;
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	t_line	line2;

	if (!line)
		line = get_empty_line();
	while (1)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == 0)
			break ;
		buffer[nb] = '\0';
		aux = ft_strjoin(line, buffer);
		free(line);
		line = aux;
		if (ft_have_line(line))
		{
			line2 = get_line(line);
			return (line2);
		}
	}
	if (ft_strlen(line) == 0)
	{
		line2.line = NULL;
		free(line);
	}
	else
	{
		line2.line = line;
		line2.storage = NULL;
	}
	return (line2);
}

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	t_line		line;

	if (fd < 0)
		return (NULL);
	if (storage && ft_have_line(storage))
	{
		line = get_line(storage);
		storage = line.storage;
		return (line.line);
	}
	line = read_file(fd, storage);
	if (line.line)
	{
		storage = line.storage;
		return (line.line);
	}
	if (storage)
	{
		line.line = storage;
		storage = NULL;
		return (line.line);
	}
	return (NULL);
}
