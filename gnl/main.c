/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 11:35:58 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/10 12:46:05 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include "gnl.h"

int	main(void)
{
	int		fd;
	char	*line;

	line = "";
	fd = open("file.txt", O_RDONLY);
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	return (0);
}
