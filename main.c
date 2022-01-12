/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:29:41 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/12 13:45:55 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "./tests/tlibft.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	colors('G');
	printf("===============\n");
	printf("  MAINS LIBFT   \n");
	printf("===============\n\n");
	colors('N');
	if (argc == 1)
	{
		test_isalpha();
		test_isdigit();
		test_isalnum();
		test_isascii();
		test_isprint();
		test_strlen();
		test_memset();
		test_bzero();
		test_memcpy();
		test_memmove();
		test_strlcpy();
		test_strlcat();
		test_toupper();
		test_tolower();
		test_strchr();
		test_strrchr();
		test_strncmp();
		test_memchr();
		test_strnstr();
		test_atoi();
		test_calloc();
		//test_strdup();
	}
	else{
		/*switch (argv[1][0])
		{
			case 'atoi': test_atoi();
			break;
		}*/
	}
	return (0);
}
