#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
private:
	T *_elements;
	unsigned int _length;

public:
	// Constructors
	Array() : _elements(NULL), _length(0)
	{
		std::cout << "\e[0;33mDefault Constructor called of Array\e[0m" << std::endl;
	}

	Array(unsigned int n) : _elements(new T[n]), _length(n)
	{
		std::cout << "\e[0;33mParameters Constructor called of Array\e[0m" << std::endl;
	}

	Array(const Array &copy) : _elements(new T[copy._length]), _length(copy._length)
	{
		copyElements(copy);
		std::cout << "\e[0;33mCopy Constructor called of Array\e[0m" << std::endl;
	}

	// Destructor
	~Array()
	{
		destroyElements();
		std::cout << "\e[0;31mDestructor called of Array\e[0m" << std::endl;
	}

	// Operators
	Array &operator=(const Array &assign)
	{
		if (&assign == this)
			return *this;
		destroyElements();
		_length = assign._length;
		_elements = new T[_length];
		copyElements(assign);
		return *this;
	}

	T &operator[](unsigned int index)
	{
		if (index >= _length)
			throw IndexEeption();
		return _elements[index];
	}

	// Getters / Setters
	T *getElements() const
	{
		return _elements;
	}

	unsigned int getLength() const
	{
		return _length;
	}

	// Exceptions
	class IndexEeption : public std::exception
	{
		virtual const char *what() const throw()
		{
			return ("Index out of bounds");
		}
	};

private:
	// Methods
	void destroyElements()
	{
		if (_elements)
			delete[] _elements;
	}

	void copyElements(const Array &copy)
	{
		for (size_t i = 0; i < copy._length; i++)
		{
			_elements[i] = copy._elements[i];
		}
	}
};

#endif