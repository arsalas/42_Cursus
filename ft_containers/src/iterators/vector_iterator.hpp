#ifndef VECTOR_ITERATOR_H
#define VECTOR_ITERATOR_H

#include <cstddef> // ptrdiff_t

#include "utils.hpp"

namespace ft
{
	template <class T, bool isconst = false >
	struct vector_iterator
	{
		// ==============================================================
		// 							MEMBER TYPES
		// ==============================================================

		typedef T value_type;
		typedef vector_iterator<T, isconst> self;
		typedef std::ptrdiff_t difference_type;
		typedef typename choose_type<isconst, const T &, T &>::type reference;
		typedef typename choose_type<isconst, const T *, T *>::type pointer;

		// ==============================================================
		// 							CONSTRUCTORS
		// ==============================================================

		vector_iterator() : _ptr(NULL) {}
		vector_iterator(value_type *ptr) : _ptr(ptr) {}
		vector_iterator(const vector_iterator<T, false> &copy) : _ptr(copy._ptr) {}

		// ==============================================================
		// 							DESTRUCTOR
		// ==============================================================

		virtual ~vector_iterator() {}

		// ==============================================================
		// 							OPERATORS
		// ==============================================================

		self &operator=(const self &rhs)
		{
			_ptr = rhs._ptr;
			return *this;
		}

		self &operator++()
		{
			_ptr++;
			return *this;
		}

		self operator++(int)
		{
			self it = *this;
			++(*this);
			return it;
		}

		self &operator--()
		{
			_ptr--;
			return *this;
		}

		self operator--(int)
		{
			self it = *this;
			--(*this);
			return it;
		}

		self operator+=(int n)
		{
			_ptr += n;
			return *this;
		}

		self operator-=(int n)
		{
			_ptr -= n;
			return *this;
		}

		self operator+(int n) const
		{
			self it(*this);
			return it += n;
		}

		self operator-(int n) const
		{
			self it(*this);
			return it -= n;
		}

		difference_type operator-(vector_iterator<T, true> it) const
		{
			return _ptr - it._ptr;
		}

		reference operator[](size_t n) const
		{
			return _ptr[n];
		}

		bool operator<(const vector_iterator<T, true> &rhs) const
		{
			return _ptr < rhs._ptr;
		}

		bool operator>(const vector_iterator<T, true> &rhs) const
		{
			return _ptr > rhs._ptr;
		}

		bool operator<=(const vector_iterator<T, true> &rhs) const
		{
			return _ptr <= rhs._ptr;
		}

		bool operator>=(const vector_iterator<T, true> &rhs) const
		{
			return _ptr >= rhs._ptr;
		}

		bool operator==(const vector_iterator<T, true> &rhs) const
		{
			return _ptr == rhs._ptr;
		}

		bool operator!=(const vector_iterator<T, true> &rhs) const
		{
			return _ptr != rhs._ptr;
		}

		reference operator*() const
		{
			return *_ptr;
		}

		pointer operator->() const
		{
			return _ptr;
		}

		friend self operator+(int n, self it)
		{
			return it += n;
		}

		friend self operator-(int n, self it)
		{
			return it -= n;
		}

		pointer _ptr;
	};

}

#endif