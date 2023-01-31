#ifndef REVERSE_ITERATOR_H
#define REVERSE_ITERATOR_H

#include "iterator_traits.hpp"

namespace ft
{
	template <typename Iterator>
	class reverse_iterator
	{
	public:
		// ==============================================================
		// 							MEMBER TYPES
		// ==============================================================

		typedef reverse_iterator self;
		typedef Iterator iterator_type;

		typedef typename iterator_traits<iterator_type>::value_type value_type;
		typedef typename iterator_traits<iterator_type>::pointer pointer;
		typedef typename iterator_traits<iterator_type>::reference reference;
		typedef typename iterator_traits<iterator_type>::difference_type difference_type;

		// ==============================================================
		// 							MEMBER FUNCTIONS
		// ==============================================================

		reverse_iterator() : _it() {}

		reverse_iterator(const iterator_type copy) : _it(copy) {}
		template <typename It>
		reverse_iterator(const reverse_iterator<It> &copy) : _it(copy._it){};

		virtual ~reverse_iterator() {}

		template <class It>
		self &operator=(const reverse_iterator<It> &other)
		{
			_it = other._it;
			return *this;
		}


		// ==============================================================
		// 							OPERATORS
		// ==============================================================

		self &operator++()
		{
			--_it;
			return *this;
		}

		self operator++(int)
		{
			self it = *this;
			--_it;
			return it;
		}

		self &operator--()
		{
			++_it;
			return *this;
		}

		self operator--(int)
		{
			self it = *this;
			++_it;
			return it;
		}

		self operator+(difference_type n) const
		{
			reverse_iterator it(*this);
			it._it -= n;
			return it;
		}

		self operator+=(difference_type n)
		{
			_it = _it - n;
			return *this;
		}

		self operator-(difference_type n) const
		{
			reverse_iterator it(*this);
			it._it += n;
			return it;
		}

		self operator-=(difference_type n)
		{
			_it = _it + n;
			return *this;
		}

		reference operator[](difference_type n) const
		{
			return *(*this + n);
		}

		reference operator*() const
		{
			iterator_type it = _it;
			return *--it;
		}

		pointer operator->() const
		{
			iterator_type it = _it;
			return &*--it;
		}

		template <class It>
		difference_type operator-(const reverse_iterator<It> &x)
		{
			return x._it.operator-(_it);
		}

		friend reverse_iterator operator+(difference_type n, const reverse_iterator &rhs)
		{
			return rhs + n;
		}

		template <class It>
		bool operator==(const reverse_iterator<It> &rhs) const
		{
			return _it == rhs._it;
		}

		template <class It>
		bool operator!=(const reverse_iterator<It> &rhs) const
		{
			return _it != rhs._it;
		}

		template <class It>
		bool operator<(const reverse_iterator<It> &rhs) const
		{
			return _it > rhs._it;
		}

		template <class It>
		bool operator>(const reverse_iterator<It> &rhs) const
		{
			return _it < rhs._it;
		}

		template <class It>
		bool operator<=(const reverse_iterator<It> &rhs) const
		{
			return _it >= rhs._it;
		}

		template <class It>
		bool operator>=(const reverse_iterator<It> &rhs) const
		{
			return _it <= rhs._it;
		}

	private:
		iterator_type _it;
	};
}

#endif