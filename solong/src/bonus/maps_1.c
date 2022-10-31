/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:22:00 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/09 13:35:18 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	*complete_map_img(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == '1')
		return (select_img(vars, "./src/images/bonus/wall.xpm"));
	else if (vars->map[i][j] == '0')
		return (select_img(vars, "./src/images/bonus/grass.xpm"));
	else if (vars->map[i][j] == 'C')
	{
		vars->collect++;
		return (select_img(vars, select_img_collect(vars->character.frame)));
	}
	else if (vars->map[i][j] == 'E')
		return (select_img(vars, "./src/images/bonus/escape.xpm"));
	else if (vars->map[i][j] == 'O')
		return (select_img(vars, select_img_enemy(vars->character.frame)));
	else if (vars->map[i][j] == 'P')
	{
		vars->character.x = j;
		vars->character.y = i;
		return (select_img_character(vars));
	}
	return (NULL);
}

void	put_enemies(int elements, t_vars *vars, t_coord c)
{
	if (elements % DIFFICULT == 0 && vars->map[c.x][c.y] == '0')
		vars->map[c.x][c.y] = 'O';
}

void	put_images(t_vars *vars, t_coord c, t_coord coord, int count)
{
	vars->img[count] = complete_map_img(vars, c.x, c.y);
	if (vars->img[count] == NULL)
		exit (0);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img[count],
		coord.x, coord.y);
}

/* *
* Pinta el mapa con las imagenes
*/
void	print_map(t_vars *vars)
{
	int		count;
	int		elements;
	t_coord	c;
	t_coord	coord;

	elements = 0;
	c.x = 0;
	count = 0;
	coord.y = 0;
	vars->collect = 0;
	while (vars->map[c.x])
	{
		c.y = 0;
		coord.x = 0;
		while (vars->map[c.x][c.y] != '\n' && vars->map[c.x][c.y])
		{
			put_enemies(elements, vars, c);
			put_images(vars, c, coord, count++);
			coord.x += SIZE_TEXTURE;
			c.y++;
			elements++;
		}
		coord.y += SIZE_TEXTURE;
		c.x++;
	}
}

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
