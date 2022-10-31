/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 23:22:33 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/14 23:22:33 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

bool found_line(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (true);
        i++;
    }
    return (false);
}

int line_len(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    return (i + 1);
}

char *extract_line(char *str)
{
    unsigned int len;
    char *new;
    int i;

    len = line_len(str);
    new = malloc(sizeof(char) * (len + 1));
    if (!new)
        return (NULL);
    i = 0;
    while (i < len)
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

int str_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *str_join(char *s1, char *buffer)
{
    unsigned int len1;
    unsigned int len2;
    char *str;
    int i;

    len1 = str_len(s1);
    if (found_line(buffer))
        len2 = line_len(buffer);
    else
        len2 = str_len(buffer);
    str = malloc(sizeof(char) * (len1 + len2 + 1));
    if (!str)
    {
        free(str);
        return (NULL);
    }
    i = 0;
    while (s1 && s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    i = 0;
    while (i < len2)
    {
        str[len1 + i] = buffer[i];
        i++;
    }
    str[len1 + i] = '\0';
    if (len1 > 0)
        free(s1);
    return (str);
}

void mem_move(char *str)
{
    int len;
    int len_max;
    int i;

    len_max = str_len(str);
    len = len_max - line_len(str);
    i = 0;
    while (i < len)
    {
        str[i] = str[len_max - i - 1];
        i++;
    }
    str[i] = '\0';
}

char    *str_dup(char *str)
{
    int     i;
    char    *new;

    i = 0;
    new = malloc(sizeof(char) * str_len(str) + 1);
    if (!new)
        return (NULL);
    while (str[i])
    {
        new[i] = str[i];
        i++;
    }
    new[i] = '\0';
    return (new);
}

char *get_next_line(int fd)
{
    char static buffer[BUFFER_SIZE + 1];
    char *str;
    int nb;

    if (found_line(buffer))
    {
        str = extract_line(buffer);
        if (str)
            mem_move(buffer);
        return (str);
    }
    if (str_len(buffer) > 0)
    {
        str = NULL;
        str = str_dup(buffer);
        if (!str)
            return (NULL);
    }
    else
        buffer[0] = '\0';
    nb = 1;
    while (nb > 0 && !found_line(buffer))
    {
        nb = read(fd, buffer, BUFFER_SIZE);
        buffer[nb] = '\0';
        str = str_join(str, buffer);
        if (!str)
            return (NULL);
    }
    mem_move(buffer);
    return (str);
}