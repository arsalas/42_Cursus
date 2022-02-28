/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:17:12 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/28 17:02:31 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	**map;
	int		x;
	int		y;
	int		movements;
}				t_vars;

void	print_map(t_vars *vars)
{
	int		i;
	int		j;
	void	*img;
	int		w;
	int		h;
	int 	x;
	int 	y;


	i = 0;
	x = 0;
	y = 0;
	while (vars->map[i])
	{
		j = 0;
		x = 0;
		while (vars->map[i][j] != '\n' && vars->map[i][j])
		{
			if (vars->map[i][j] == '1')
			{
				img = mlx_xpm_file_to_image(vars->mlx, "./src/images/rock.xpm", &w, &h);
				mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
				x += 32;
			}
			else if (vars->map[i][j] == '0')
			{
				img = mlx_xpm_file_to_image(vars->mlx, "./src/images/water.xpm", &w, &h);
				mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
				x += 32;
			}
			else if (vars->map[i][j] == 'C')
			{
				img = mlx_xpm_file_to_image(vars->mlx, "./src/images/fish.xpm", &w, &h);
				mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
				x += 32;
			}
			else if (vars->map[i][j] == 'E')
			{
				img = mlx_xpm_file_to_image(vars->mlx, "./src/images/escape.xpm", &w, &h);
				mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
				x += 32;
			}
			else if (vars->map[i][j] == 'P')
			{
				img = mlx_xpm_file_to_image(vars->mlx, "./src/images/water.xpm", &w, &h);
				mlx_put_image_to_window(vars->mlx, vars->win, img, x, y);
				vars->x = j;
				vars->y = i;
				vars->img = mlx_xpm_file_to_image(vars->mlx, "./src/images/char.xpm", &w, &h);
				mlx_put_image_to_window(vars->mlx, vars->win, vars->img, x, y);
				x += 32;
			}
			j++;
		}
		y += 32;
		i++;
	}
}

/*
W: 		13
A: 		0
S: 		1
D: 		2
UP: 	126 
DOWN: 	125
LEFT: 	123
RIGHT: 	124
ESC: 	53
*/
int	events(int keycode, t_vars *vars)
{
	int	w;
	int	h;
	void	*img;

	vars->movements++;
	printf("movements: %i\n", vars->movements);
	mlx_destroy_image(vars->mlx, vars->img);
	vars->img = mlx_xpm_file_to_image(vars->mlx, "./src/images/char.xpm", &w, &h);
	img = mlx_xpm_file_to_image(vars->mlx, "./src/images/water.xpm", &w, &h);
	mlx_put_image_to_window(vars->mlx, vars->win, img, vars->x * 32, vars->y * 32);
	if (vars->map[vars->y - 1][vars->x] == 'E')
		exit(0);
	if (keycode == 13 || keycode == 126)
	{
		if (vars->map[vars->y - 1][vars->x] != '1')
			vars->y--;
	}
	if (keycode == 1 || keycode == 125)
	{
		if (vars->map[vars->y + 1][vars->x] != '1')
			vars->y++;
	}
	if (keycode == 0 || keycode == 123)
	{
		if (vars->map[vars->y][vars->x - 1] != '1')
			vars->x--;
	}
	if (keycode == 2 || keycode == 124)
	{
		if (vars->map[vars->y][vars->x + 1] != '1')
			vars->x++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x * 32, vars->y * 32);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		width;
	int		height;

	if (argc == 1)
		return (0);
	vars.map = read_map(argv[1]);
	vars.movements = 0;
	width = (ft_strlen(vars.map[0]) - 1) * 32;
	height = array_str_count(vars.map) * 32;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "so_long");
	print_map(&vars);
	mlx_hook(vars.win, 2, 0, events, &vars);
	mlx_loop(vars.mlx);
}

