

#ifndef SORTING_H
# define SORTING_H


typedef enum e_options_type
{
	ROT,
	REV,
	ROT_REV,
	REV_ROT
}	t_options_type;

typedef struct s_option
{
	int				movs_rotate_a;
	int				movs_rotate_b;
	int				movs_reverse_a;
	int				movs_reverse_b;
	int				quantity_moves;
	t_options_type	type;

}	t_option;


#endif
