/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:50:09 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/09 13:50:17 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

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
