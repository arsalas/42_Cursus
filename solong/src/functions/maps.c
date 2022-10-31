/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:27:13 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/09 13:55:19 by aramirez         ###   ########.fr       */
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
