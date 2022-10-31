/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:57:53 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/08 12:11:08 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

#include <stdio.h>
#include <string.h>
#include <limits.h>

char    *get_next_line(int fd);
int     contain_line(char *str);
int     strlenline(char *str);
void    str_join(char *storage, char *str);
void    mem_move(char *str, int len);
void    mem_zero(char *str);
int     ft_strlen(char *str);

#endif