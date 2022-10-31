/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:39:52 by aramirez          #+#    #+#             */
/*   Updated: 2022/06/27 14:18:44 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void)
{
	char *line = readline("Enter text: ");
	printf("line: %s", line);
	// 	F_OK flag : Used to check for existence of file.
	// R_OK flag : Used to check for read permission bit.
	// W_OK flag : Used to check for write permission bit.
	// X_OK flag : Used to check for execute permission bit.
	printf("\naccess: %i\n", access("./test", F_OK));
	return 0;
}