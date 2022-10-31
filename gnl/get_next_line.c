/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:23:05 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/08 12:10:29 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

/**
 * Comprobar si hay un salto de linea
*/
int contain_line(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

int str_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void    push_str(char *storage, char *str)
{
    int i;
    int len;

    len = str_len(storage);
    i = 0;
    while (str[i])
    {
        storage[len + i] = str[i];
        i++;
    }
    storage[len + i] = '\0';
}

int count_line(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\n')
        i++;
    return (i + 1);
}

void    mem_move(char *storage)
{
    int start;
    int i;

    start = count_line(storage);
    i = 0;
    while (storage[start + i])
    {
        storage[i] = storage[start + i];
        i++;
    }
    storage[i] = '\0';
}

char    *extract_line(char *storage)
{
    int     len;
    char    *str;
    int     i;

    len = count_line(storage);
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = storage[i];
        i++;
    }
    mem_move(storage);
    return (str);
}
char    *extract_last_line(char *storage)
{
    int     len;
    char    *str;
    int     i;

    len = str_len(storage);
    if (len == 0)
        return (NULL);
    str = malloc(sizeof(char) * (len + 1));
    if (str == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = storage[i];
        storage[i] = '\0';
        i++;
    }
    return (str);
}

/**
 * Obtener la linea siguiente de un fichero
 */
char *get_next_line(int fd)
{
    static char storage[INT_MAX];
    int     nb;
    char    buffer[BUFFER_SIZE];

    if (fd == -1 || fd > FOPEN_MAX)
        return (NULL);
    // Comprobar si hay una linea almacenada
    if (contain_line(storage) == 1)
         return (extract_line(storage));
    while (1)
    {
        nb = read(fd, buffer, BUFFER_SIZE);
        // Problemas de lectura
        if (nb == -1)
            return (NULL);
        // No ha leido nada
        if (nb == 0)
            return (extract_last_line(storage));
        push_str(storage, buffer);
        if(contain_line(storage) == 1)
            break ;
    }
    return (extract_line(storage));
}
