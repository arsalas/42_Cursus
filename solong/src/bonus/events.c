/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:05:25 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/09 15:33:43 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

int	keydown(int keycode, t_vars *vars)
{
	char		dir;

	vars->last_key = keycode;
	dir = get_direction(keycode);
	if (dir != ' ')
	{
		vars->character.is_moving = 1;
		vars->character.direction = dir;
		if (can_move(vars, vars->character.direction) == 1)
		{
			move_char(vars, vars->character.direction);
			printf("Movements: %i\n", ++vars->movements);
		}
	}
	if (vars->map[vars->character.y][vars->character.x] == 'E'
		&& vars->collect == 0)
		exit(0);
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	fix_char(vars);
	return (0);
}

int	keyup(int keycode, t_vars *vars)
{
	if (keycode == 13 || keycode == 126
		|| keycode == 1 || keycode == 125
		|| keycode == 0 || keycode == 123
		|| keycode == 2 || keycode == 124)
		vars->character.is_moving = 0;
	return (0);
}

int	close_event(int keycode, t_vars *vars)
{
	exit(0);
	vars->last_key = keycode;
}
