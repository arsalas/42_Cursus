#ifndef STACK_H
#define STACK_H

#include "vector.hpp"
#include "debug.hpp"

namespace ft
{

	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		// ==============================================================
		// 							MEMBER TYPES
		// ==============================================================

		typedef T value_type;
		typedef Container container_type;
		typedef std::size_t size_type;

		// ==============================================================
		// 							MEMBER FUNCTIONS
		// ==============================================================

		/**
		 * @brief A container adaptor keeps internally a container object as data. This container object is a copy of the ctnr argument passed to the constructor, if any, otherwise it is an empty container.
		 * @param ctnr Container object.
		 */
		explicit stack(const container_type &ctnr = container_type())
			: c(ctnr)
		{
			printDebug("\e[0;33mDefault Constructor called of stack\e[0m\n");
		}

		/**
		 * @brief Destroys the container object.
		 */
		~stack()
		{
			printDebug("\e[0;31mDestructor called of stack\e[0m\n");
		}

		/**
		 * @brief Returns whether the stack is empty: i.e. whether its size is zero.
		 *
		 * @return true if the underlying container's size is 0, false otherwise.
		 */
		bool empty() const
		{
			return c.empty();
		}

		/**
		 * @brief Returns the number of elements in the stack.
		 * @return The number of elements in the underlying container.
		 */
		size_type size() const
		{
			return c.size();
		}

		/**
		 * @brief Returns a reference to the top element in the stack.
		 * Since stacks are last-in first-out containers, the top element is the last element inserted into the stack.
		 * @return A reference to the top element in the stack.
		 */
		value_type &top()
		{
			return c.back();
		}

		/**
		 * @brief Returns a const reference to the top element in the stack.
		 * Since stacks are last-in first-out containers, the top element is the last element inserted into the stack.
		 * @return A const reference to the top element in the stack.
		 */
		const value_type &top() const
		{
			return c.back();
		}

		/**
		 * @brief Inserts a new element at the top of the stack, above its current top element. The content of this new element is initialized to a copy of val.
		 * This member function effectively calls the member function push_back of the underlying container object.
		 * @param val Value to which the inserted element is initialized.
		 */
		void push(const value_type &val)
		{
			c.push_back(val);
		}

		/**
		 * @brief Removes the element on top of the stack, effectively reducing its size by one.
		 * The element removed is the latest element inserted into the stack, whose value can be retrieved by calling member stack::top.
		 */
		void pop()
		{
			c.pop_back();
		}

		template <class T1, class C1>
		friend bool operator==(const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);

		template <class T1, class C1>
		friend bool operator<(const stack<T1, C1> &lhs, const stack<T1, C1> &rhs);

	protected:
		container_type c;
	};

	// ==============================================================
	// 							NON-MEMBER FUNCTIONS
	// ==============================================================
	template <class T, class Ctnr>
	bool operator==(const stack<T, Ctnr> &lhs, const stack<T, Ctnr> &rhs)
	{
		return lhs.c == rhs.c;
	}

	template <class T, class Ctnr>
	bool operator<(const stack<T, Ctnr> &lhs, const stack<T, Ctnr> &rhs)
	{
		return lhs.c < rhs.c;
	}

	template <class T, class Ctnr>
	bool operator!=(const stack<T, Ctnr> &lhs, const stack<T, Ctnr> &rhs)
	{
		return !(lhs == rhs);
	}

	template <class T, class Ctnr>
	bool operator<=(const stack<T, Ctnr> &lhs, const stack<T, Ctnr> &rhs)
	{
		return !(rhs < lhs);
	}

	template <class T, class Ctnr>
	bool operator>(const stack<T, Ctnr> &lhs, const stack<T, Ctnr> &rhs)
	{
		return rhs < lhs;
	}

	template <class T, class Ctnr>
	bool operator>=(const stack<T, Ctnr> &lhs, const stack<T, Ctnr> &rhs)
	{
		return !(lhs < rhs);
	}
}

#endif