/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_char_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 13:08:45 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/09 13:18:02 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

char	*char_up(int frame, int is_moving)
{
	if (is_moving == 1)
	{
		if (frame == 1)
			return ("./src/images/bonus/char/Run_U_1.xpm");
		if (frame == 2)
			return ("./src/images/bonus/char/Run_U_2.xpm");
		if (frame == 3)
			return ("./src/images/bonus/char/Run_U_1.xpm");
		if (frame == 4)
			return ("./src/images/bonus/char/Run_U_2.xpm");
	}
	else
	{
		if (frame == 1)
			return ("./src/images/bonus/char/Idle_U_1.xpm");
		if (frame == 2)
			return ("./src/images/bonus/char/Idle_U_2.xpm");
		if (frame == 3)
			return ("./src/images/bonus/char/Idle_U_3.xpm");
		if (frame == 4)
			return ("./src/images/bonus/char/Idle_U_4.xpm");
	}
	return (NULL);
}

char	*char_down(int frame, int is_moving)
{
	if (is_moving == 1)
	{
		if (frame == 1)
			return ("./src/images/bonus/char/Run_D_1.xpm");
		if (frame == 2)
			return ("./src/images/bonus/char/Run_D_2.xpm");
		if (frame == 3)
			return ("./src/images/bonus/char/Run_D_1.xpm");
		if (frame == 4)
			return ("./src/images/bonus/char/Run_D_3.xpm");
	}
	else
	{
		if (frame == 1)
			return ("./src/images/bonus/char/Idle_D_1.xpm");
		if (frame == 2)
			return ("./src/images/bonus/char/Idle_D_2.xpm");
		if (frame == 3)
			return ("./src/images/bonus/char/Idle_D_3.xpm");
		if (frame == 4)
			return ("./src/images/bonus/char/Idle_D_4.xpm");
	}
	return (NULL);
}

char	*char_left(int frame, int is_moving)
{
	if (is_moving == 1)
	{
		if (frame == 1)
			return ("./src/images/bonus/char/Run_L_1.xpm");
		if (frame == 2)
			return ("./src/images/bonus/char/Run_L_2.xpm");
		if (frame == 3)
			return ("./src/images/bonus/char/Run_L_1.xpm");
		if (frame == 4)
			return ("./src/images/bonus/char/Run_L_3.xpm");
	}
	else
	{
		if (frame == 1)
			return ("./src/images/bonus/char/Idle_L_1.xpm");
		if (frame == 2)
			return ("./src/images/bonus/char/Idle_L_2.xpm");
		if (frame == 3)
			return ("./src/images/bonus/char/Idle_L_3.xpm");
		if (frame == 4)
			return ("./src/images/bonus/char/Idle_L_4.xpm");
	}
	return (NULL);
}

char	*char_right(int frame, int is_moving)
{
	if (is_moving == 1)
	{
		if (frame == 1)
			return ("./src/images/bonus/char/Run_R_1.xpm");
		if (frame == 2)
			return ("./src/images/bonus/char/Run_R_2.xpm");
		if (frame == 3)
			return ("./src/images/bonus/char/Run_R_1.xpm");
		if (frame == 4)
			return ("./src/images/bonus/char/Run_R_3.xpm");
	}
	else
	{
		if (frame == 1)
			return ("./src/images/bonus/char/Idle_R_1.xpm");
		if (frame == 2)
			return ("./src/images/bonus/char/Idle_R_2.xpm");
		if (frame == 3)
			return ("./src/images/bonus/char/Idle_R_3.xpm");
		if (frame == 4)
			return ("./src/images/bonus/char/Idle_R_4.xpm");
	}
	return (NULL);
}
