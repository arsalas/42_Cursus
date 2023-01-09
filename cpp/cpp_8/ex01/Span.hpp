#ifndef SPAN_H
#define SPAN_H

#include <iostream>
#include <string>
#include <vector>

class Span
{
private:
	unsigned int _max;
	std::vector<int> _elements;

public:
	// Constructors
	Span();
	Span(const Span &copy);
	Span(unsigned int max);

	// Destructor
	~Span();

	// Operators
	Span &operator=(const Span &assign);

	// Getters / Setters
	unsigned int getMax() const;
	std::vector<int> getElements() const;

	// Methods
	void addNumber(int number);
	void addRange(int start, int end);
	long shortestSpan() const;
	long longestSpan() const;

	// Exceptions
	class MaxNumbersStoredException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class NotNumbersStoredException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class IncorrectRangeException : public std::exception
	{
		virtual const char *what() const throw();
	};

private:
	// Methods
	long getDistance(int n1, int n2) const;

};

#endif