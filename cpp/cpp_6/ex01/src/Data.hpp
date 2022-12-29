#ifndef DATA_H
#define DATA_H

#include <stdint.h>
#include <iostream>

struct Data
{
	std::string raw;
};

long long serialize(Data *ptr);
Data *deserialize(uintptr_t raw);

#endif