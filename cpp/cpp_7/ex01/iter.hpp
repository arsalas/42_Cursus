#ifndef ITER_H
#define ITER_H

#include <iostream>

template <typename T>
void iter(T *array, size_t arraySize, void (*fn)(T &))
{
	for (size_t i = 0; i < arraySize; i++)
	{
		fn(array[i]);
	}
}

#endif