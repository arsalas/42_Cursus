#ifndef VECTOR_H
#define VECTOR_H

#ifndef DEBUG
#define DEBUG 0
#endif

#include <iostream>
#include <memory>
#include <iterator>
#include <algorithm>

namespace ft
{

	template <typename T>
	class Vector
	{
	private:
		int value_type;
		int allocator_type;
		int reference;
		int const_reference;
		int pointer;
		int const_pointer;
		int iterator;
		int const_iterator;
		int reverse_iterator;
		int const_reverse_iterator;
		int size_type;

	public:
		// Constructors
		Vector()
		{
			if (DEBUG)
				std::cout << "\e[0;33mDefault Constructor called of Vector\e[0m" << std::endl;
		}

		Vector(unsigned int n)
		{
			if (DEBUG)
				std::cout << "\e[0;33mParameters Constructor called of Vector\e[0m" << std::endl;
		}

		Vector(const Vector &copy)
		{
			if (DEBUG)
				std::cout << "\e[0;33mCopy Constructor called of Vector\e[0m" << std::endl;
		}

		// Destructor
		~Vector()
		{
			if (DEBUG)
				std::cout << "\e[0;31mDestructor called of Vector\e[0m" << std::endl;
		}

		// Methods
	};

}
#endif