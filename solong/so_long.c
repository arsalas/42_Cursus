/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:17:12 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/04 19:15:39 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*complete_map_img(t_vars *vars, int i, int j)
{
	if (vars->map[i][j] == '1')
		return (select_img(vars, "./src/images/wall.xpm"));
	else if (vars->map[i][j] == '0')
		return (select_img(vars, "./src/images/water.xpm"));
	else if (vars->map[i][j] == 'C')
	{
		vars->collect++;
		return (select_img(vars, "./src/images/collectable.xpm"));
	}
	else if (vars->map[i][j] == 'E')
		return (select_img(vars, "./src/images/escape.xpm"));
	else if (vars->map[i][j] == 'P')
	{
		vars->character.x = j;
		vars->character.y = i;
		return (select_img_character(vars));
	}
	return (NULL);
}

void	print_map(t_vars *vars)
{
	int		count;
	t_coord	c;
	t_coord	coord;

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
			vars->img[count] = complete_map_img(vars, c.x, c.y);
			if (vars->img[count] == NULL)
				exit (0);
			mlx_put_image_to_window(vars->mlx, vars->win, vars->img[count++],
				coord.x, coord.y);
			coord.x += SIZE_TEXTURE;
			c.y++;
		}
		coord.y += SIZE_TEXTURE;
		c.x++;
	}
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		width;
	int		height;

	if (argc == 1)
	{
		exit (0);
	}
	vars.map = read_map(argv[1]);
	validate_map(vars.map);
	vars.movements = 0;
	vars.img = create_img_arr(&vars);
	if (vars.img == NULL)
		return (0);
	width = (ft_strlen(vars.map[0]) - 1) * SIZE_TEXTURE;
	height = array_str_count(vars.map) * SIZE_TEXTURE;
	vars.mlx = mlx_init();
	vars.character.direction = 'D';
	vars.win = mlx_new_window(vars.mlx, width, height, "so_long");
	print_map(&vars);
	mlx_hook(vars.win, 2, 0, events, &vars);
	mlx_hook(vars.win, 17, 0, close_event, &vars);
	mlx_loop(vars.mlx);
}
