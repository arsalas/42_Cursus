/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 00:44:23 by aramirez          #+#    #+#             */
/*   Updated: 2022/04/09 00:44:23 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int str_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

void print_str(char *str)
{
    write(1, str, str_len(str));
}

int find_letter(char c, char *str)
{
    static int i = 0;

    while (str[i])
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}
int main(int argc, char **argv)
{
    char *str;
    char *letters;
    int i;
    int counter;

    if (argc > 2)
    {
        str = argv[1];
        letters = argv[2];
        i = 0;
        counter = 0;
        while (str[i])
        {
            if (find_letter(str[i], letters) == 1)
                counter++;
            i++;
        }
        if (counter == str_len(str))
            print_str(str);
    }
    print_str("\n");
    return (0);
}