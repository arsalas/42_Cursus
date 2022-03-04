/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:23:17 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/04 19:24:45 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	*select_img(t_vars *vars, char *image)
{
	void	*img;
	int		img_size;

	img = mlx_xpm_file_to_image(vars->mlx, image,
			&img_size, &img_size);
	return (img);
}

void	*select_img_character(t_vars *vars)
{
	if (vars->character.direction == 'U')
		return (select_img(vars, "./src/images/char_u.xpm"));
	else if (vars->character.direction == 'D')
		return (select_img(vars, "./src/images/char_d.xpm"));
	else if (vars->character.direction == 'L')
		return (select_img(vars, "./src/images/char_l.xpm"));
	else if (vars->character.direction == 'R')
		return (select_img(vars, "./src/images/char_r.xpm"));
	return (NULL);
}

void	free_img(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->img[i])
	{
		mlx_destroy_image(vars->mlx, vars->img[i]);
		i++;
	}
}
