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

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	get_len(char *str, char type)
{
	int	i;

	i = 0;
	if (type == 'l')
	{
		while (str[i] != '\n')
		i++;
	}
	else if (type == 's')
	{
		while (str[i] != '\0')
		i++;
	}
	if (str[i] == '\n')
		i++;
	return (i);
}

void	delete_line(char *str)
{
	int	len;
	int	i;

	len = get_len(str, 'l');
	i = 0;
	while (str[len + i])
	{
		str[i] = str[len + i];
		i++;
	}
	str[i] = '\0';
}

char	*get_line(char *str)
{
	int		len;
	char	*line;
	int		i;

	len = get_len(str, 'l');
	line = malloc(sizeof(char) * (len + 2));
	i = 0;
	while (i < len)
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	delete_line(str);
	return (line);
}

char	*augment_storage(char *aux)
{
	char	*str;
	int		i;
	int		len;

	if (aux == NULL)
		len = 0;
	else
		len = get_len(aux, 's');
	str = malloc(sizeof(char) * (BUFFER_SIZE + len + 1));
	if(len > 0)
	{
		while (aux[i])
		{
			str[i] = aux[i];
			i++;
		}
	}
	else
		str[0] = '\0';
	return (str);
}

void	concat_line(char *str, char *buffer)
{
	int	i;
	int	len;

	i = 0;
	len = get_len(str, 's');
	while (i + len < BUFFER_SIZE)
	{
		str[len + i] = buffer[i];
		i++;
	}
	str[len + i] = '\0';
	free(buffer);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*aux;
	int			numbytes;
	if (contain_line(aux) == 1)
	{
		return (get_line(aux));
	}
	aux = augment_storage(aux);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	numbytes = read(fd, buffer, BUFFER_SIZE);
	concat_line(aux, buffer);
	return (get_next_line(fd));
}
