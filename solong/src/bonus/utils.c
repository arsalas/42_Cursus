/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 13:06:25 by aramirez          #+#    #+#             */
/*   Updated: 2022/03/07 12:42:10 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long_bonus.h"

char	**arr_push(char **arr, char *str)
{
	int		i;
	int		n;
	char	**new;

	i = 0;
	n = array_str_count(arr);
	new = ft_calloc(sizeof(char *), n + 2);
	while (i < n)
	{
		new[i] = arr[i];
		i++;
	}
	new[i] = str;
	free(arr);
	return (new);
}

int	array_str_count(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
		i++;
	return (i);
}

void	exit_error(char *msg)
{
	if (msg)
		printf("%s\n", msg);
	printf("Error\n");
	exit(0);
}

int	get_total_img(t_vars *vars)
{
	int		i;
	int		len;

	len = array_str_count(vars->map);
	i = 0;
	while (vars->map[0][i] == '1')
		i++;
	return (i * len);
}

void	**create_img_arr(t_vars *vars)
{
	int	count;

	count = get_total_img(vars);
	return (ft_calloc(sizeof(void *), count + 1));
}
