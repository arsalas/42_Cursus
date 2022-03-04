/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:27:13 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/01 14:20:01 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	is_map_rectangle(char **map)
{
	size_t	size;
	int		i;
	int		len;

	i = 0;
	size = 0;
	len = array_str_count(map);
	while (i < len)
	{
		if (i == 0)
			size = ft_strlen(map[i]);
		else if (size != ft_strlen(map[i]) && i < len - 1)
			return (0);
		else if (size != ft_strlen(map[i]) + 1 && i == len - 1)
			return (0);
		i++;
	}
	return (1);
}

int	map_is_close(char **map)
{
	int	i;
	int	j;
	int	len;
	int	end;

	len = array_str_count(map);
	end = ft_strlen(map[0]) - 1;
	i = 0;
	j = 0;
	while (j < end)
	{
		if (map[0][j] != '1' || map[len - 1][j] != '1')
			return (0);
		j++;
	}
	i++;
	while (i < len - 1)
	{
		if (map[i][0] != '1' || map[i][end - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	count_map_char(char **map, char sign)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == sign)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

/*
Comprobar si el mapa tiene un formato valido 
(cerrado por paredes y caractes validos) 01CEP
al menos 1 salida, 1 coleccionable y 1 posicion inicial
mapa rectangular
*/
void	validate_map(char **map)
{
	int	errors;

	errors = 0;
	if (is_map_rectangle(map) == 0)
		errors += printf("Map must be a rectangle\n");
	if (map_is_close(map) == 0)
		errors += printf("Map must be close by walls\n");
	if (count_map_char(map, 'E') < 1)
		errors += printf("Map must be almost 1 escape\n");
	if (count_map_char(map, 'C') < 1)
		errors += printf("Map must be almost 1 collectable\n");
	if (count_map_char(map, 'P') != 1)
		errors += printf("Map must be only 1 position\n");
	if (errors > 1)
		exit_error(NULL);
}

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
