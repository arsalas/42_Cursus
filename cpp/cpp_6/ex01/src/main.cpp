#include <iostream>
#include "Data.hpp"

int main()
{
	Data data1;
	data1.raw = "Hola Mundo";

	uintptr_t raw = serialize(&data1);
	Data *data2 = deserialize(raw);

	std::cout << "data1 -> " << data1.raw << std::endl;
	std::cout << "data2 -> " << data2->raw << std::endl;
}