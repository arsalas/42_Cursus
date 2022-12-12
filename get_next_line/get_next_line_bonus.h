/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:33:10 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/12 12:34:17 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_line
{
	char	*line;
	char	*storage;
}	t_line;

char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlen(char *s, int is_line);
int		ft_have_line(char *s);
char	*get_next_line(int fd);

#endif