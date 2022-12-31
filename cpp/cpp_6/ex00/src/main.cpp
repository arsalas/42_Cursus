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
	// float f = atof("-inff");
	// std::cout << atoi(argv[1]) << std::endl;
	// std::cout << f << std::endl;
	// char c = static_cast<char>(f);
	// if (c == 0)
	// 	std::cout << "NULL" << std::endl;
	// std::cout << c << std::endl;

	// std::cout << atof(argv[1]) << std::endl;
	// std::cout << 42.10f << std::endl;
	Conversor conv = Conversor(argv[1]);
	std::cout << conv << std::endl;
	return 0;
}
