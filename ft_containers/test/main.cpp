#include <iostream>
#include "test.hpp"

int main(int argc, char *argv[])
{
	for (int i = 1; i < argc; i++)
	{
		if ((std::string)argv[i] == "vector")
			vectorTest();
		if ((std::string)argv[i] == "map")
			mapTest();
		if ((std::string)argv[i] == "stack")
			stackTest();
	}

	if (argc == 1)
	{
		vectorTest();
		mapTest();
		stackTest();
	}

	return 0;
}

// MINE
// ./bin/ft_containers 1  81.88s user 7.72s system 76% cpu 1:57.81 total
// STD
// ./bin/ft_containers 1  1.20s user 4.30s system 27% cpu 20.180 total