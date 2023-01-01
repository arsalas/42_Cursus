#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>
#include <iterator>
#include <algorithm>

namespace ft
{

	template <typename T>
	class vector
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
		vector()
		{
			std::cout << "\e[0;33mDefault Constructor called of vector\e[0m" << std::endl;
		}

		vector(unsigned int n)
		{
			std::cout << "\e[0;33mParameters Constructor called of vector\e[0m" << std::endl;
		}

		vector(const vector &copy)
		{
			std::cout << "\e[0;33mCopy Constructor called of vector\e[0m" << std::endl;
		}

		// Destructor
		~vector()
		{
			std::cout << "\e[0;31mDestructor called of vector\e[0m" << std::endl;
		}

		// Methods
	};

}
#endif