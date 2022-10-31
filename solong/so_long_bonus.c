/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:17:12 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/09 15:33:29 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	render_next_frame(t_vars *vars)
{
	vars->frames++;
	if (vars->frames == 3)
	{
		vars->frames = 0;
		vars->character.frame++;
		if (vars->character.frame == 5)
			vars->character.frame = 1;
	}
	free_img(vars);
	mlx_clear_window(vars->mlx, vars->win);
	print_map(vars);
	mlx_string_put(vars->mlx, vars->win, 16, 16, 16777215,
		ft_strjoin("MOVEMENTS ", ft_itoa(vars->movements)));
	mlx_string_put(vars->mlx, vars->win, 15, 15, 0,
		ft_strjoin("MOVEMENTS ", ft_itoa(vars->movements)));
	return (1);
}

void	init_vars(t_vars *vars)
{
	vars->character.direction = 'D';
	vars->last_key = 0;
	vars->finish_mov = 1;
	vars->frames = 0;
	vars->character.frame = 1;
	vars->character.is_moving = 0;
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		width;
	int		height;
	int		i;

	i = 0;
	if (argc == 1)
		exit (0);
	vars.map = read_map(argv[1]);
	validate_map(vars.map);
	vars.movements = 0;
	vars.img = create_img_arr(&vars);
	if (vars.img == NULL)
		return (0);
	width = (ft_strlen(vars.map[0]) - 1) * SIZE_TEXTURE;
	height = array_str_count(vars.map) * SIZE_TEXTURE;
	vars.mlx = mlx_init();
	init_vars(&vars);
	vars.win = mlx_new_window(vars.mlx, width, height, "so_long");
	print_map(&vars);
	mlx_hook(vars.win, 2, 0, keydown, &vars);
	mlx_hook(vars.win, 3, 0, keyup, &vars);
	mlx_hook(vars.win, 17, 0, close_event, &vars);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
}
