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
	std::cout << atoi(argv[1]) << std::endl;
	std::cout << atof("-inf") << std::endl;
	std::cout << static_cast<char>(42) << std::endl;
	std::cout << atof(argv[1]) << std::endl;
	// Conversor conv = Conversor(argv[1]);
	// std::cout << conv << std::endl;
	return 0;
}
