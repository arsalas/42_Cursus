#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>

template <typename T>
void swap(T &n1, T &n2)
{
	T temporal;
	temporal = n1;
	n1 = n2;
	n2 = temporal;
}

template <typename T>
T const &min(T const &n1, T const &n2)
{
	if (n1 < n2)
		return n1;
	return n2;
}

template <typename T>
T const &max(T const &n1, T const &n2)
{
	if (n2 >= n1)
		return n2;
	return n1;
}
#endif