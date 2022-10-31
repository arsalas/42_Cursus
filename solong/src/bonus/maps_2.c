/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:22:00 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/09 13:53:48 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

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

int	count_map_extratype(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' &&
				map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != 'P'
				&& map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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
	if (count_map_extratype(map) == 1)
		errors += printf("Map type not valid\n");
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

void	fix_char(t_vars *vars)
{
	int	i;		
	int	j;

	if (count_map_char(vars->map, 'P') > 1)
	{
		i = 0;
		while (vars->map[i])
		{
			j = 0;
			while (vars->map[i][j])
			{
				if (vars->map[i][j] == 'P')
				{
					vars->map[i][j] = '0';
					return ;
				}
				j++;
			}
			i++;
		}
	}
}
