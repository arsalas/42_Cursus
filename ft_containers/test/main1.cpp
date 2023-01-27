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
