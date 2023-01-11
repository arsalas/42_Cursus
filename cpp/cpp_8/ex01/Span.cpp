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
	_elements = assign._elements;
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
void Span::addRange(int start, int end)
{
	if (start > end)
		throw IncorrectRangeException();
	for (int i = start; i <= end; i++)
	{
		addNumber(i);
	}
}

void Span::addNumber(int number)
{
	if (_elements.size() == _max)
		throw MaxNumbersStoredException();
	_elements.push_back(number);
}

long Span::shortestSpan() const
{
	long shortest, distance;
	std::vector<int> sorter(_elements);
	if (_elements.size() < 2)
		throw NotNumbersStoredException();
	sort(sorter.begin(), sorter.end());
	shortest = getDistance(sorter[1], sorter[0]);
	if (_elements.size() == 2)
		return shortest;
	for (std::vector<int>::iterator iter = sorter.begin(); iter < sorter.end() - 1; iter++)
	{
		distance = getDistance(*(iter + 1), *iter);
		if (distance < shortest)
			shortest = distance;
	}
	return shortest;
}

long Span::longestSpan() const
{
	int max, min;
	std::vector<int> sorter(_elements);
	if (_elements.size() < 2)
		throw NotNumbersStoredException();
	sort(sorter.begin(), sorter.end());
	max = *max_element(_elements.begin(), _elements.end());
	min = *min_element(_elements.begin(), _elements.end());
	return getDistance(min, max);
}

long Span::getDistance(long n1, long n2) const
{
	long distance = abs(n2 - n1);
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

const char *Span::IncorrectRangeException::what() const throw()
{
	return "Incorrect range, must use addRange(int min, int max)";
}
