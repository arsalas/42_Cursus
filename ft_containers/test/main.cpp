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
	}

	if (argc == 1)
	{
		vectorTest();
		mapTest();
	}

	return 0;
}
