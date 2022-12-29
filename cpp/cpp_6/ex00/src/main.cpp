#include <iostream>
#include <math.h>
#include <limits>

#include "Conversor.hpp"

int main(int argc, char const *argv[])
{
	if (argc != 2)
	{
		std::cout << "Incorrect arguments number" << std::endl;
		return 1;
	}
	Conversor conv = Conversor(argv[1]);
	std::cout << conv << std::endl;
	return 0;
}
