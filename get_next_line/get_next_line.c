/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:35:04 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 12:32:45 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

/**
 * @brief Get the line of string and storage leftover 
 * 
 * @param line 
 * @return t_line 
 */
static t_line	get_line(char *line)
{
	int			len;
	char		*leftover;
	char		*aux;
	t_line		result;

	len = ft_strlen(line, 1);
	result.line = ft_substr(line, 0, len);
	leftover = ft_substr(line, len, ft_strlen(line, 0));
	if (!result.line || !leftover)
	{
		result.line = NULL;
		return (result);
	}
	free(line);
	result.storage = leftover;
	return (result);
}

/**
 * @brief Get the null line object
 * 
 * @return t_line 
 */
static t_line	get_null_line(void)
{
	t_line	line2;

	line2.line = NULL;
	return (line2);
}

/**
 * @brief Read file until enf of file or find end of line
 * 
 * @param fd 
 * @param line 
 * @return t_line 
 */
static t_line	read_file(int fd, char *line)
{
	int		nb;
	char	buffer[BUFFER_SIZE + 1];
	char	*aux;
	t_line	line2;

	while (1)
	{
		nb = read(fd, buffer, BUFFER_SIZE);
		if (nb == 0)
			break ;
		buffer[nb] = '\0';
		aux = ft_strjoin(line, buffer);
		if (!aux)
			return (get_null_line());
		free(line);
		line = aux;
		if (ft_have_line(line))
		{
			line2 = get_line(line);
			return (line2);
		}
	}
	return (get_null_line());
}

/**
 * @brief Get the line file object
 * 
 * @param fd 
 * @param line 
 * @return t_line 
 */
static t_line	get_line_file(int fd, char *line)
{
	t_line	line2;

	if (!line)
	{
		line = malloc(sizeof(char));
		line[0] = '\0';
	}
	line2 = read_file(fd, line);
	if (line2.line)
		return (line2);
	if (ft_strlen(line, 0) == 0)
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

/**
 * @brief Get the next line object
 * 
 * @param fd 
 * @return char* 
 */
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
	line = get_line_file(fd, storage);
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
