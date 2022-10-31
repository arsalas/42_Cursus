/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:47:44 by aramirez          #+#    #+#             */
/*   Updated: 2022/07/01 14:47:45 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

void toUpper(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (isupper(str[i]) == 0 && isalpha(str[i]) != 0)
            str[i] = (toupper(str[i]));
        i++;
    }
}

void megaphone(int len, char **words)
{
    if (len == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < len; i++)
    {
        toUpper(words[i]);
        std::cout << words[i];
        if (i < len - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[])
{
    megaphone(argc, argv);
    return (0);
}