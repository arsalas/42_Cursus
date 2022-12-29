#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int search)
{
	typename T::iterator result = find(container.begin(), container.end(), search);
	if (result == container.end())
		return container.end();
	return result;
}

#endif