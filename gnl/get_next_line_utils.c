/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 12:23:05 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/08 12:10:29 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line.h"

/**
 * Comprobamos si en el storage hay una linea guardada 
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

/**
 * Contador de caracteres de una string hasta \n incluido 
*/
int strlenline(char *str)
{
    int i;

    if (!str)
        return (0);
    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    return (i + 1);
}

/**
 * Unimos la segunda string a la primera
*/
void str_join(char *storage, char *str)
{
    long long len;
    int i;

    len = ft_strlen(storage);
    i = 0;
    while (str[i])
    {
        storage[len + i] = str[i];
        i++;
    }
    free(str);
}

/**
 *  Desplazamos los caracteres del resto del storage al principio 
*/
void mem_move(char *str, int len)
{
    int i;

    i = 0;
    while (str[len + i])
    {
        str[i] = str[len + i];
        i++;
    }
    str[i] = '\0';
}

/**
 * Borramos la memoria de la str con \0 
*/
void    mem_zero(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        str[i] = '\0';
        i++;
    }
}

