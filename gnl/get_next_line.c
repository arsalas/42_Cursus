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
 * Obtener la str de la linea de el storage
 */
char *extract_line(char *str)
{
    int len;
    char *n_str;
    int i;

    len = strlenline(str);
    n_str = malloc(sizeof(char) * (len + 1));
    if (!n_str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        n_str[i] = str[i];
        i++;
    }
    n_str[i] = '\0';
    return (n_str);
}

/**
 * Contar la cantidad de caracteres de una string
 */
int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

/**
 * Obtener la ultima linea en el storage
 */
char *get_last_line(char *str)
{
    int len;
    char *n_str;
    int i;

    len = ft_strlen(str);
    n_str = malloc(sizeof(char) * (len + 1));
    if (!n_str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        n_str[i] = str[i];
        str[i] = '\0';
        i++;
    }
    n_str[i] = '\0';
    return (n_str);
}

/**
 * Cuando no leemos mas bytes del fichero comprobamos si queda algo en
 * el storage para devolver la ultima line o devolver un NULL
 */
char *no_read(char *storage)
{
    if (ft_strlen(storage) > 0)
        return (get_last_line(storage));
    else
        return (NULL);
}

/**
 * Obtener la linea siguiente de un fichero
 */
char *get_next_line(int fd)
{
    char        *buf;
    static char storage[INT_MAX];
    size_t      nbytes;
    char        *str;

    if (fd == -1)
        return (NULL);
    if (contain_line(storage) == 1)
    {
        str = extract_line(storage);
        if (ft_strlen(str) != ft_strlen(storage))
            mem_move(storage, ft_strlen(str));
        else
            mem_zero(storage);
        return (str);
    }
    buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buf)
        return (buf);
    nbytes = read(fd, buf, BUFFER_SIZE);
    if (nbytes == -1)
        return (NULL);
    if (nbytes == 0)
        return (no_read(storage));
    buf[nbytes] = '\0';
    str_join(storage, buf);
    return (get_next_line(fd));
}
