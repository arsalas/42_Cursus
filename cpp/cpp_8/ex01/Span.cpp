#include <algorithm>
#include <cstdlib>
#include <iterator>
#include "Span.hpp"

// Constructors
Span::Span() : _max(0)
{
	std::cout << "\e[0;33mDefault Constructor called of Span\e[0m" << std::endl;
}

Span::Span(const Span &copy) : _max(copy._max), _elements(copy._elements)
{
	std::cout << "\e[0;33mCopy Constructor called of Span\e[0m" << std::endl;
}

Span::Span(unsigned int max) : _max(max)
{
	std::cout << "\e[0;33mFields Constructor called of Span\e[0m" << std::endl;
}

// Destructor
Span::~Span()
{
	std::cout << "\e[0;31mDestructor called of Span\e[0m" << std::endl;
}

// Operators
Span &Span::operator=(const Span &assign)
{
	if (this == &assign)
		return *this;
	_max = assign.getMax();
	_elements = assign.getElements();
	return *this;
}

// Getters / Setters
unsigned int Span::getMax() const
{
	return _max;
}

std::vector<int> Span::getElements() const
{
	return _elements;
}

// Methods
void Span::addNumber(int number)
{
	if (_elements.size() == _max)
		throw MaxNumbersStoredException();
	_elements.push_back(number);
}

int Span::shortestSpan()
{
	int shortest, distance;
	shortest = getDistance(_elements[1], _elements[0]);
	if (_elements.size() == 2)
		return shortest;
	for (size_t i = 1; i < _elements.size() - 1; i++)
	{
		distance = getDistance(_elements[i + 1], _elements[i]);
		if (distance < shortest)
			shortest = distance;
	}
	return shortest;
}

int Span::longestSpan()
{
	int longest, distance;
	longest = getDistance(_elements[1], _elements[0]);
	if (_elements.size() == 2)
		return longest;
	for (size_t i = 1; i < _elements.size() - 1; i++)
	{
		distance = getDistance(_elements[i + 1], _elements[i]);
		if (distance > longest)
			longest = distance;
	}
	return longest;
}

unsigned int Span::getDistance(int n1, int n2)
{
	int distance = n2 - n1;
	if (distance < 0)
		distance *= -1;
	return distance;
}


// Exceptions
const char *Span::MaxNumbersStoredException::what() const throw()
{
	return "Cannot store any more numbers";
}

const char *Span::NotNumbersStoredException::what() const throw()
{
	return "Not enough numbers stored to provide a span";
}
