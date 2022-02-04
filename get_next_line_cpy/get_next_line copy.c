/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:14:42 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/03 19:29:01 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	char	*buffer;
	char	*aux;
	int		numbytes;
	int		i;
	int		n;
	char	*str;

	buffer = calloc(1, BUFFER_SIZE);
	if (buffer == NULL)
		return (NULL);
	str = NULL;
	i = 1;
	numbytes = 10;
	while (numbytes > 0 && buffer[0] != '\n')
	{
		aux = malloc((i + 1) * sizeof(char));
		if (aux == NULL)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		if (buffer == NULL)
		{
			free(buffer);
			return (NULL);
		}
		if (str == NULL)
		{
			str = malloc(sizeof(char) * 2);
			if (str == NULL)
			{
				free(buffer);
				free(aux);
				return (NULL);
			}
			numbytes = read(fd, buffer, 1);
			if (numbytes == 0)
			{
				free(buffer);
				free(str);
				free(aux);
				return (NULL);
			}
			str[0] = buffer[0];
			str[1] = '\0';
			i++;
			continue ;
		}
		else
		{
			n = 0;
			while (str[n])
			{
				aux[n] = str[n];
				n++;
			}
			numbytes = read(fd, buffer, 1);
			if (numbytes == 0)
			{
				free(buffer);
				free(str);
				free(aux);
				return (NULL);
			}
			aux[n] = buffer[0];
			aux[n + 1] = '\0';
		}
		free(str);
		str = malloc((i + 1) * sizeof(char));
		n = 0;
		while (aux[n])
		{
			str[n] = aux[n];
			n++;
		}
		str[n] = '\0';
		free(aux);
		i++;
	}
	n = 0;
	free(buffer);
	return (str);
}
