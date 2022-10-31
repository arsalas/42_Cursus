/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:23:17 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/09 13:18:33 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

char	*char_path_image_idle(char dir, int frame)
{
	if (dir == 'U')
		return (char_up(frame, 0));
	if (dir == 'D')
		return (char_down(frame, 0));
	if (dir == 'L')
		return (char_left(frame, 0));
	if (dir == 'R')
		return (char_right(frame, 0));
	return (NULL);
}

char	*char_path_image_moving(char dir, int frame)
{
	if (dir == 'U')
		return (char_up(frame, 1));
	if (dir == 'D')
		return (char_down(frame, 1));
	if (dir == 'L')
		return (char_left(frame, 1));
	if (dir == 'R')
		return (char_right(frame, 1));
	return (NULL);
}

void	*select_img_character(t_vars *vars)
{
	if (vars->character.is_moving == 1)
		return (select_img(vars, char_path_image_moving(
					vars->character.direction, vars->character.frame)));
	else
		return (select_img(vars, char_path_image_idle(
					vars->character.direction, vars->character.frame)));
}
