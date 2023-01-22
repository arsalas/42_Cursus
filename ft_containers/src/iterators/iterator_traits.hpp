#ifndef ITERATOR_TRAITS_H
#define ITERATOR_TRAITS_H

#include <cstddef>

namespace ft
{

	template <class Iterator>
	struct iterator_traits
	{
		// ==============================================================
		// 							MEMBER TYPES
		// ==============================================================

		// Type to express the result of subtracting one iterator from another.
		typedef typename Iterator::difference_type difference_type;
		// The type of the element the iterator can point to.
		typedef typename Iterator::value_type value_type;
		// The type of a pointer to an element the iterator can point to.
		typedef typename Iterator::pointer pointer;
		// The type of a reference to an element the iterator can point to.
		typedef typename Iterator::reference reference;
		// The iterator category. It can be one of these:
		typedef typename Iterator::iterator_category iterator_category;
	};

	template <class T>
	struct iterator_traits<T * >
	{
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T *pointer;
		typedef T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

	template <class T>
	struct iterator_traits<const T * >
	{
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef const T *pointer;
		typedef const T &reference;
		typedef std::random_access_iterator_tag iterator_category;
	};

}

#endif