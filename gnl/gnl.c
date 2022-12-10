/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:35:04 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/10 12:53:17 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*storage = NULL;
	char		buffer[BUFFER_SIZE + 1];
	char		*line;
	char		*aux;
	int			nb;
	int			len;
	char		*leftover;

	if (storage)
	{
		if (ft_have_line(storage))
		{
			line = storage;
			len = ft_strlen_line(line);
			aux = ft_substr(line, 0, len + 1);
			leftover = ft_substr(line, len + 1, ft_strlen(line));
			free(line);
			storage = leftover;
			return (aux);
		}
		else
			line = storage;
	}
	else
	{
		line = malloc(sizeof(char));
		line[0] = '\0';
	}
	nb = 1;
	while (nb > 0)
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
			len = ft_strlen_line(line);
			aux = ft_substr(line, 0, len + 1);
			leftover = ft_substr(line, len + 1, ft_strlen(line));
			free(line);
			storage = leftover;
			return (aux);
		}
	}
	if (storage)
	{
		storage = NULL;
		return (line);
	}
	return (NULL);
}
