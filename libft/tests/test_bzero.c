#include <stdio.h>
#include <string.h>
#include "../libft.h"
#include "./tlibft.h"

int		test_bzero(void)
{
	char	str[50];
	char	str2[50];
	colors('Y');
	printf("===============\n");
	printf("8. FT_BZERO:\n");
	printf("===============\n");
	colors('N');
	strcpy(str,"This is string.h library function");
	strcpy(str2,"This is string.h library function");
	puts(str);
	bzero(str,7);
	ft_bzero(str2,7);
	puts(str);
	puts(str2);
	return (0);
}