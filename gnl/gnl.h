/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:33:10 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/11 22:55:10 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# define BUFFER_SIZE 42

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
int		ft_strlen(char *s);
int		ft_strlen_line(char *s);
int		ft_have_line(char *s);
char	*get_next_line(int fd);

#endif