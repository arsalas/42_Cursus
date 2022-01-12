#include <stdio.h>

void	colors(char color)
{
	if (color == 'R') printf("\033[0;31m");
	else if (color == 'Y') printf("\033[0;33m");
	else if (color == 'G') printf("\033[0;32m");
	else if (color == 'N') printf("\033[0m");
}