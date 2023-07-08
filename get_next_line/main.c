/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:19:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/02/08 11:41:45 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	fd = open("nl.txt", O_RDONLY);
	//fd = open("files/empty", O_RDWR);
	// printf("fd: %i\n", fd);
	// close(fd);
	// printf("fd: %i\n", fd);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	/*printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));*/
	return (0);
}
