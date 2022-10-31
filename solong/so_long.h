/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:47:41 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/09 13:56:07 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SIZE_TEXTURE 32
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>
# include "src/gnl/get_next_line.h"

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_character
{
	char	direction;
	int		x;
	int		y;
}	t_character;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		**img;
	char		**map;
	int			collect;
	int			movements;
	t_character	character;
}	t_vars;

char	**read_map(char *src_map);
int		array_str_count(char **arr);
void	*select_img(t_vars *vars, char *image);
void	*select_img_character(t_vars *vars);
int		events(int keycode, t_vars *vars);
int		close_event(int keycode, t_vars *vars);
void	validate_map(char **map);
void	print_map(t_vars *vars);
char	**arr_push(char **arr, char *str);
void	exit_error(char *msg);
void	**create_img_arr(t_vars *vars);
void	free_img(t_vars *vars);

#endif