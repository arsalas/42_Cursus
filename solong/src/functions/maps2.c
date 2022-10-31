/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:55:39 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/09 13:55:52 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*
Leer el mapa y convertirlo en una array
*/
char	**read_map(char *src_map)
{
	char	**map;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	fd = open(src_map, O_RDONLY);
	if (fd == -1)
		exit_error("Map not found\n");
	map = ft_calloc(sizeof(char *), 1);
	if (map == NULL)
		exit_error("Memory error\n");
	while (1)
	{
		line = get_next_line(fd);
		if (line != NULL)
			map = arr_push(map, line);
		else
			break ;
		i++;
	}
	close(fd);
	return (map);
}
