#ifndef MAP_ITERATOR_H
#define MAP_ITERATOR_H

#include <cstddef> // ptrdiff_t
#include <memory>

#include "pair.hpp"

namespace ft
{

	template <typename T>
	struct Tree
	{
		bool unused_;

		Tree *_left;
		Tree *_right;
		Tree *_parent;
		T _pair;
	};

	template <class Key, class T, bool isconst = false>
	struct map_iterator
	{
		// ==============================================================
		// 							MEMBER TYPES
		// ==============================================================
		typedef map_iterator<Key, T, isconst> self;
		typedef std::ptrdiff_t difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef ft::pair<const Key, T> value_type;
		typedef typename choose_type<isconst, const value_type &, value_type &>::type reference;
		typedef typename choose_type<isconst, const value_type *, value_type *>::type pointer;
		typedef typename choose_type<isconst, const Tree<value_type> *, Tree<value_type> *>::type nodeptr;

		// ==============================================================
		// 							MEMBER FUNCTIONS
		// ==============================================================
		map_iterator() : _pointer(NULL) {}
		map_iterator(nodeptr ptr) : _pointer(ptr) {}
		map_iterator(const map_iterator<Key, T, false> &copy) : _pointer(copy._pointer) {}
		map_iterator(const map_iterator<Key, T, true> &copy) : _pointer(copy._pointer) {}

		virtual ~map_iterator() {}

		// ==============================================================
		// 							OPERATORS
		// ==============================================================
		self &operator=(const self &rhs)
		{
			_pointer = rhs._pointer;
			return *this;
		}

		self &operator++()
		{
			if ((_pointer->_right && _pointer->_right->_parent != _pointer) || (_pointer->_left && _pointer->_left->_parent != _pointer))
				_pointer = _pointer->_left;
			else if (_pointer->_right)
			{
				_pointer = _pointer->_right;
				while (_pointer->_left)
					_pointer = _pointer->_left;
			}
			else
			{
				nodeptr it = _pointer->_parent;
				while (_pointer == it->_right)
				{
					_pointer = it;
					it = it->_parent;
				}
				if (_pointer->_right != it)
					_pointer = it;
			}
			return *this;
		}

		self operator++(int)
		{
			self tmp = *this;
			++(*this);
			return tmp;
		}

		self &operator--()
		{
			if ((_pointer->_right && _pointer->_right->_parent != _pointer) || (_pointer->_left && _pointer->_left->_parent != _pointer))
				_pointer = _pointer->_right;
			else if (_pointer->_left)
			{
				_pointer = _pointer->_left;
				while (_pointer->_right)
					_pointer = _pointer->_right;
			}
			else
			{
				nodeptr tmp = _pointer->_parent;

				while (_pointer == tmp->_left)
				{
					_pointer = tmp;
					tmp = tmp->_parent;
				}
				_pointer = tmp;
			}
			return *this;
		}

		self operator--(int)
		{
			self tmp = *this;
			--(*this);
			return tmp;
		}

		bool operator==(const self &rhs) const
		{
			return _pointer == rhs._pointer;
		}

		bool operator!=(const self &rhs) const
		{
			return _pointer != rhs._pointer;
		}

		reference operator*() const
		{
			return _pointer->pair_;
		}
		
		pointer operator->() const
		{
			return &_pointer->pair_;
		}

		nodeptr _pointer;
	};
}

#endif