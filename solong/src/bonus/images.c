/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 12:23:17 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/09 13:11:19 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

void	*select_img(t_vars *vars, char *image)
{
	void	*img;
	int		img_size;

	img = mlx_xpm_file_to_image(vars->mlx, image,
			&img_size, &img_size);
	return (img);
}

char	*select_img_collect(int frame)
{
	if (frame == 1)
		return ("./src/images/bonus/collectable/collectable_1.xpm");
	if (frame == 2)
		return ("./src/images/bonus/collectable/collectable_2.xpm");
	if (frame == 3)
		return ("./src/images/bonus/collectable/collectable_3.xpm");
	if (frame == 4)
		return ("./src/images/bonus/collectable/collectable_3.xpm");
	return ("./src/images/bonus/collectable/collectable_1.xpm");
}

char	*select_img_enemy(int frame)
{
	if (frame == 1)
		return ("./src/images/bonus/enemy/octorok_1.xpm");
	if (frame == 2)
		return ("./src/images/bonus/enemy/octorok_2.xpm");
	if (frame == 3)
		return ("./src/images/bonus/enemy/octorok_3.xpm");
	if (frame == 4)
		return ("./src/images/bonus/enemy/octorok_3.xpm");
	return ("./src/images/bonus/enemy/octorok_1.xpm");
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
