/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 14:47:41 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/09 15:27:40 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define SIZE_TEXTURE 32
# define DIFFICULT 30
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include "./src/gnl/get_next_line.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdio.h>

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
	int		frame;
	int		is_moving;
}	t_character;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	void		**img;
	char		**map;
	int			collect;
	int			frames;
	int			ememies;
	int			movements;
	int			last_key;
	int			finish_mov;
	t_character	character;
}	t_vars;

char	**read_map(char *src_map);
int		array_str_count(char **arr);
void	*select_img(t_vars *vars, char *image);
void	*select_img_character(t_vars *vars);
int		keydown(int keycode, t_vars *vars);
int		keyup(int keycode, t_vars *vars);
int		close_event(int keycode, t_vars *vars);
void	validate_map(char **map);
void	print_map(t_vars *vars);
char	**arr_push(char **arr, char *str);
void	exit_error(char *msg);
void	**create_img_arr(t_vars *vars);
void	free_img(t_vars *vars);
void	*complete_map_img(t_vars *vars, int i, int j);
void	print_map(t_vars *vars);
char	*select_img_collect(int frame);
char	*select_img_enemy(int frame);
void	fix_char(t_vars *vars);
int		can_move(t_vars *vars, char dir);
char	get_direction(int keycode);
void	move_char(t_vars *vars, char dir);
char	*char_up(int frame, int is_moving);
char	*char_down(int frame, int is_moving);
char	*char_left(int frame, int is_moving);
char	*char_right(int frame, int is_moving);
int		count_map_char(char **map, char sign);
int		map_is_close(char **map);
int		is_map_rectangle(char **map);

#endif