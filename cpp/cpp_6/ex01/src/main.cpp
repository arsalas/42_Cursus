#include <iostream>
#include "Data.hpp"


int main()
{
	Data data1;
	data1.raw = "Lorem Ipsum";

	uintptr_t raw = serialize(&data1);
	Data *data2 = deserialize(raw);

	std::cout << data2->raw << std::endl;
}