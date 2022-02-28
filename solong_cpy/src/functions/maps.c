/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 13:27:13 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/28 14:25:12 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

/*
Comprobar si el mapa tiene un formato valido 
(cerrado por paredes y caractes validos) 01CEP
al menos 1 salida, 1 coleccionable y 1 posicion inicial
mapa rectangular
*/
int	is_map_valid(void)
{
	return (1);
}

int	array_str_count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

char	**arr_push(char **arr, char *str)
{
	int		i;
	int		n;
	char	**new;

	i = 0;
	n = array_str_count(arr);
	new = ft_calloc(sizeof(char *), n + 2);
	while (i < n)
	{
		new[i] = arr[i];
		i++;
	}
	new[i] = str;
	free(arr);
	return (new);

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
		return (NULL);
	map = ft_calloc(sizeof(char *), 1);
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
