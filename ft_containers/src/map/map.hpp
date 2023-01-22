#ifndef MAP_H
#define MAP_H

#include <memory>
#include "pair.hpp"
#include "utils.hpp"

#include "map_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = ft::less<Key>,
			  class Alloc = std::allocator<ft::pair<const Key, T>>>
	class map
	{
	public:
		// ==============================================================
		// 							MEMBER TYPES
		// ==============================================================

		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const key_type, mapped_type> value_type;
		typedef Compare key_compare;
		typedef ft::Comp<Compare, value_type> value_compare;

		typedef Alloc allocator_type;
		;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		typedef ft::map_iterator<key_type, mapped_type> iterator;
		typedef ft::map_iterator<key_type, mapped_type, true> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;

		// ==============================================================
		// 							MEMBER FUNCTIONS
		// ==============================================================

		/**
		 * @brief Constructs an empty container, with no elements.
		 *
		 * @param comp Binary predicate that, taking two element keys as argument, returns true if the first argument goes before the second argument in the strict weak ordering it defines, and false otherwise.
		 * @param alloc Allocator object.
		 */
		explicit map(
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type())
		{
			_alloc = alloc;
			comp_ = comp;
			size_ = 0;

			_container = alloc_node_.allocate(1);
			_container->left_ = _container;
			_container->right_ = _container;
			_container->parent_ = NULL;

			_alloc.construct(&_container->pair_, value_type());
		}

		/**
		 * @brief Constructs a container with as many elements as the range [first,last), with each element constructed from its corresponding element in that range.
		 *
		 * @tparam InputIterator
		 * @param first Input iterators to the initial positions in a range.
		 * @param last Input iterators to the final positions in a range.
		 * @param comp Binary predicate that, taking two element keys as argument, returns true if the first argument goes before the second argument in the strict weak ordering it defines, and false otherwise.
		 * @param alloc Allocator object.
		 */
		template <class InputIterator>
		map(
			InputIterator first, InputIterator last,
			const key_compare &comp = key_compare(),
			const allocator_type &alloc = allocator_type())
		{
			alloc_ = alloc;
			comp_ = comp;
			size_ = 0;
			container_ = alloc_node_.allocate(1);
			container_->left_ = container_;
			container_->right_ = container_;
			container_->parent_ = NULL;
			alloc_.construct(&container_->pair_, value_type());
			insert(first, last);
		}

		/**
		 * @brief Constructs a container with a copy of each of the elements in x.
		 *
		 * @param x Another map object of the same type (with the same class template arguments Key, T, Compare and Alloc), whose contents are either copied or acquired.
		 */
		map(const map &x)
		{
			comp_ = x.comp_;
			size_ = 0;
			alloc_ = x.alloc_;

			container_ = alloc_node_.allocate(1);
			container_->left_ = container_;
			container_->right_ = container_;
			container_->parent_ = NULL;
			alloc_.construct(&container_->pair_, value_type());

			insert(x.begin(), x.end());
		}

		/**
		 * @brief Destroys the container object.
		 *
		 */
		~map()
		{
			clear();
			alloc_.destroy(&container_->pair_);
			alloc_node_.deallocate(container_, 1);
		}

		/**
		 * @brief Copies all the elements from x into the container, changing its size accordingly.
		 * The container preserves its current allocator, which is used to allocate additional storage if needed.
		 * @param x A map object of the same type (i.e., with the same template parameters, key, T, Compare and Alloc).
		 * @return *this
		 */
		map &operator=(const map &x)
		{
			clear();
			insert(x.begin(), x.end());
			return *this;
		}

		// ==============================================================
		// 							ITERATORS
		// ==============================================================

		/**
		 * @brief Returns an iterator referring to the first element in the map container.
		 * Because map containers keep their elements ordered at all times, begin points to the element that goes first following the container's sorting criterion.
		 * If the container is empty, the returned iterator value shall not be dereferenced.
		 * @return An iterator to the first element in the container.
		 */
		iterator begin()
		{
			return iterator(get_left());
		}
		/**
		 * @brief Returns an iterator referring to the first element in the map container.
		 * Because map containers keep their elements ordered at all times, begin points to the element that goes first following the container's sorting criterion.
		 * If the container is empty, the returned iterator value shall not be dereferenced.
		 * @return An iterator to the first element in the container.
		 */
		const_iterator begin() const
		{
			return const_iterator(get_left());
		}

		/**
		 * @brief Returns an iterator referring to the past-the-end element in the map container.
		 * The past-the-end element is the theoretical element that would follow the last element in the map container. It does not point to any element, and thus shall not be dereferenced.
		 * Because the ranges used by functions of the standard library do not include the element pointed by their closing iterator, this function is often used in combination with map::begin to specify a range including all the elements in the container.
		 * If the container is empty, this function returns the same as map::begin.
		 * @return An iterator to the past-the-end element in the container.
		 */
		iterator end()
		{
			return iterator(container_);
		}

		/**
		 * @brief Returns an iterator referring to the past-the-end element in the map container.
		 * The past-the-end element is the theoretical element that would follow the last element in the map container. It does not point to any element, and thus shall not be dereferenced.
		 * Because the ranges used by functions of the standard library do not include the element pointed by their closing iterator, this function is often used in combination with map::begin to specify a range including all the elements in the container.
		 * If the container is empty, this function returns the same as map::begin.
		 * @return An iterator to the past-the-end element in the container.
		 */
		const_iterator end() const
		{
			return const_iterator(container_);
		}

		/**
		 * @brief Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).
		 * Reverse iterators iterate backwards: increasing them moves them towards the beginning of the container.
		 * rbegin points to the element preceding the one that would be pointed to by member end.
		 * @return A reverse iterator to the reverse beginning of the sequence container.
		 */
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		/**
		 * @brief Returns a reverse iterator pointing to the last element in the container (i.e., its reverse beginning).
		 * Reverse iterators iterate backwards: increasing them moves them towards the beginning of the container.
		 * rbegin points to the element preceding the one that would be pointed to by member end.
		 * @return A reverse iterator to the reverse beginning of the sequence container.
		 */
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}

		/**
		 * @brief Returns a reverse iterator pointing to the theoretical element right before the first element in the map container (which is considered its reverse end).
		 * The range between map::rbegin and map::rend contains all the elements of the container (in reverse order).
		 * @return A reverse iterator to the reverse end of the sequence container.
		 */
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		/**
		 * @brief Returns a reverse iterator pointing to the theoretical element right before the first element in the map container (which is considered its reverse end).
		 * The range between map::rbegin and map::rend contains all the elements of the container (in reverse order).
		 * @return A reverse iterator to the reverse end of the sequence container.
		 */
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

		// ==============================================================
		// 							CAPACITY
		// ==============================================================

		/**
		 * @brief Returns whether the map container is empty (i.e. whether its size is 0).
		 * This function does not modify the container in any way. To clear the content of a map container, see map::clear.
		 * @return true if the container size is 0, false otherwise.
		 */
		bool empty() const
		{
			return size_ == 0;
		}

		/**
		 * @brief Returns the number of elements in the map container.
		 *
		 * @return The number of elements in the container.
		 */
		size_type size() const
		{
			return size_;
		}

		/**
		 * @brief Returns the maximum number of elements that the map container can hold.
		 * This is the maximum potential size the container can reach due to known system or library implementation limitations, but the container is by no means guaranteed to be able to reach that size: it can still fail to allocate storage at any point before that size is reached.
		 * @return The maximum number of elements a map container can hold as content.
		 */
		size_type max_size() const
		{
			return alloc_node_.max_size();
		}

		// ==============================================================
		// 							ELEMENT ACCESS
		// ==============================================================

		/**
		 * @brief If k matches the key of an element in the container, the function returns a reference to its mapped value.
		 * If k does not match the key of any element in the container, the function inserts a new element with that key and returns a reference to its mapped value. Notice that this always increases the container size by one, even if no mapped value is assigned to the element (the element is constructed using its default constructor).
		 * A similar member function, map::at, has the same behavior when an element with the key exists, but throws an exception when it does not.
		 * @param k Key value of the element whose mapped value is accessed.
		 * @return A reference to the mapped value of the element with a key value equivalent to k.
		 */
		mapped_type &operator[](const key_type &k)
		{
			return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
		}

		// TODO lanzar excepcion si no se encuentra
		// TODO Comprobar si funciona
		/**
		 * @brief Returns a reference to the mapped value of the element identified with key k.
		 * If k does not match the key of any element in the container, the function throws an out_of_range exception.
		 * @param k Key value of the element whose mapped value is accessed.
		 * @return mapped_type&
		 */
		mapped_type &at(const key_type &k);
		{
			return (*((this->insert(ft::make_pair(k, mapped_type()))).first)).second;
		}

		// ==============================================================
		// 							MODIFIERS
		// ==============================================================
		/**
		 * @brief Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
		 * (single element)
		 * @param val Value to be copied to (or moved as) the inserted element.
		 * @return return a pair, with its member pair::first set to an iterator pointing to either the newly inserted element or to the element with an equivalent key in the map.
		 */
		pair<iterator, bool> insert(const value_type &val)
		{
			tree *exist = key_exists_recurse(get_root(), val.first);

			if (exist)
				return ft::make_pair(iterator(exist), false);
			size_++;
			return ft::make_pair(iterator(insert_node(container_, comp_, val)), true);
		}

		/**
		 * @brief Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
		 * (with hint)
		 * @param position Hint for the position where the element can be inserted.
		 * @param val Value to be copied to (or moved as) the inserted element.
		 * @return return an iterator pointing to either the newly inserted element or to the element that already had an equivalent key in the map.
		 */
		iterator insert(iterator position, const value_type &val)
		{
			(void)position;
			tree *exist = key_exists_recurse(get_root(), val.first);

			if (exist)
				return iterator(exist);
			size_++;
			return iterator(insert_node(container_, comp_, val));
		}

		/**
		 * @brief Extends the container by inserting new elements, effectively increasing the container size by the number of elements inserted.
		 * (range)
		 * @tparam InputIterator
		 * @param first Iterators specifying a range of elements. Copies of the elements in the range [first,last) are inserted in the container.
		 * @param last Iterators specifying a range of elements. Copies of the elements in the range [first,last) are inserted in the container.
		 */
		template <class InputIterator>
		void insert(
			InputIterator first,
			InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			while (first != last)
			{
				insert(*first);
				first++;
			}
		}

		/**
		 * @brief Removes from the map container either a single element or a range of elements ([first,last)).
		 * This effectively reduces the container size by the number of elements removed, which are destroyed.
		 * @param position Iterator pointing to a single element to be removed from the map.
		 */
		void erase(iterator position)
		{
			tree *current = position.ptr_;
			tree *tmp = NULL;

			if (current->left_)
			{
				tmp = current->left_;
				while (tmp->right_)
					tmp = tmp->right_;
				if (tmp->parent_->right_ == tmp)
				{
					if (tmp->left_)
					{
						tmp->parent_->right_ = tmp->left_;
						tmp->left_->parent_ = tmp->parent_;
					}
					else
						tmp->parent_->right_ = NULL;
				}
				tmp->right_ = current->right_;
				if (current->right_)
					current->right_->parent_ = tmp;
				if (current->left_ != tmp)
					tmp->left_ = current->left_;
				if (current->left_)
					current->left_->parent_ = tmp;
				tmp->parent_ = current->parent_;
			}
			else if (current->right_)
			{
				tmp = current->right_;
				tmp->parent_ = current->parent_;
			}
			if (current->parent_->left_ == current)
				current->parent_->left_ = tmp;
			else
				current->parent_->right_ = tmp;
			if (current == get_root())
				container_->parent_ = tmp;
			alloc_.destroy(&current->pair_);
			alloc_node_.deallocate(current, 1);
			size_--;
			set_left_right();
		}

		/**
		 * @brief Removes from the map container either a single element or a range of elements ([first,last)).
		 * This effectively reduces the container size by the number of elements removed, which are destroyed.
		 * @param k Key of the element to be removed from the map.
		 * @return returns the number of elements erased.
		 */
		size_type erase(const key_type &k)
		{
			iterator it = begin();
			iterator tmp;
			size_type count = 0;

			while (it != end())
			{
				if (!comp_(it->first, k) && !comp_(k, it->first))
				{
					erase(it);
					count++;
					return count;
				}
				else
					it++;
			}
			return count;
		}

		/**
		 * @brief Removes from the map container either a single element or a range of elements ([first,last)).
		 * This effectively reduces the container size by the number of elements removed, which are destroyed.
		 * @param first Iterators specifying a range within the map container to be removed: [first,last)
		 * @param last Iterators specifying a range within the map container to be removed: [first,last)
		 */
		void erase(iterator first, iterator last)
		{
			iterator tmp;

			while (first != last)
			{
				tmp = first++;
				erase(tmp);
			}
		}

		/**
		 * @brief Exchanges the content of the container by the content of x, which is another map of the same type. Sizes may differ.
		 * After the call to this member function, the elements in this container are those which were in x before the call, and the elements of x are those which were in this. All iterators, references and pointers remain valid for the swapped objects.
		 * Notice that a non-member function exists with the same name, swap, overloading that algorithm with an optimization that behaves like this member function.
		 * @param x Another map container of the same type as this (i.e., with the same template parameters, Key, T, Compare and Alloc) whose content is swapped with that of this container.
		 */
		void swap(map &x)
		{
			tree *tmp;
			size_type size_tmp;

			size_tmp = size_;
			size_ = x.size_;
			x.size_ = size_tmp;

			tmp = container_;
			container_ = x.container_;
			x.container_ = tmp;
		}

		/**
		 * @brief Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
		 */
		void clear()
		{
			erase(begin(), end());
		}

		// TODO comprobar si hay que hacer el emplace

		// ==============================================================
		// 							OBSERVERS
		// ==============================================================
		/**
		 * @brief Returns a copy of the comparison object used by the container to compare keys.
		 * The comparison object of a map object is set on construction. Its type (member key_compare) is the third template parameter of the map template. By default, this is a less object, which returns the same as operator<.
		 * This object determines the order of the elements in the container: it is a function pointer or a function object that takes two arguments of the same type as the element keys, and returns true if the first argument is considered to go before the second in the strict weak ordering it defines, and false otherwise.
		 * Two keys are considered equivalent if key_comp returns false reflexively (i.e., no matter the order in which the keys are passed as arguments).
		 * @return The comparison object.
		 */
		key_compare key_comp() const
		{
			return key_compare();
		}

		/**
		 * @brief Returns a comparison object that can be used to compare two elements to get whether the key of the first one goes before the second.
		 * The arguments taken by this function object are of member type value_type (defined in map as an alias of pair<const key_type,mapped_type>), but the mapped_type part of the value is not taken into consideration in this comparison.
		 * The comparison object returned is an object of the member type map::value_compare, which is a nested class that uses the internal comparison object to generate the appropriate comparison functional class.
		 * @return The comparison object for element values.
		 */
		value_compare value_comp() const
		{
			return value_compare(key_compare());
		}

		// ==============================================================
		// 							OPERATIONS
		// ==============================================================
		/**
		 * @brief Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.
		 * Two keys are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the elements are passed as arguments).
		 * Another member function, map::count, can be used to just check whether a particular key exists.
		 * @param k Key to be searched for.
		 * @return An iterator to the element, if an element with specified key is found, or map::end otherwise.
		 */
		iterator find(const key_type &k)
		{
			tree *found = key_exists_recurse(get_root(), k);

			if (found)
				return iterator(found);
			return (end());
		}

		/**
		 * @brief Searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.
		 * Two keys are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the elements are passed as arguments).
		 * Another member function, map::count, can be used to just check whether a particular key exists.
		 * @param k Key to be searched for.
		 * @return An const iterator to the element, if an element with specified key is found, or map::end otherwise.
		 */
		const_iterator find(const key_type &k) const
		{
			tree *found = key_exists_recurse(get_root(), k);

			if (found)
				return const_iterator(found);
			return (end());
		}

		/**
		 * @brief Searches the container for elements with a key equivalent to k and returns the number of matches.
		 * Because all elements in a map container are unique, the function can only return 1 (if the element is found) or zero (otherwise).
		 * Two keys are considered equivalent if the container's comparison object returns false reflexively (i.e., no matter the order in which the keys are passed as arguments).
		 * @param k Key to search for.
		 * @return if the container contains an element whose key is equivalent to k, or zero otherwise.
		 */
		size_type count(const key_type &k) const
		{
			return key_count_recurse(get_root(), k);
		}

		/**
		 * @brief Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
		 * The function uses its internal comparison object (key_comp) to determine this, returning an iterator to the first element for which key_comp(element_key,k) would return false.
		 * If the map class is instantiated with the default comparison type (less), the function returns an iterator to the first element whose key is not less than k.
		 * A similar member function, upper_bound, has the same behavior as lower_bound, except in the case that the map contains an element with a key equivalent to k: In this case, lower_bound returns an iterator pointing to that element, whereas upper_bound returns an iterator pointing to the next element.
		 * @param k Key to search for.
		 * @return An iterator to the the first element in the container whose key is not considered to go before k, or map::end if all keys are considered to go before k.
		 */
		iterator lower_bound(const key_type &k)
		{
			iterator it = begin();

			while (it != end())
			{
				if (!comp_(it->first, k))
					return it;
				it++;
			}
			return it;
		}

		/**
		 * @brief Returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
		 * The function uses its internal comparison object (key_comp) to determine this, returning an iterator to the first element for which key_comp(element_key,k) would return false.
		 * If the map class is instantiated with the default comparison type (less), the function returns an iterator to the first element whose key is not less than k.
		 * A similar member function, upper_bound, has the same behavior as lower_bound, except in the case that the map contains an element with a key equivalent to k: In this case, lower_bound returns an iterator pointing to that element, whereas upper_bound returns an iterator pointing to the next element.
		 * @param k Key to search for.
		 * @return An const iterator to the the first element in the container whose key is not considered to go before k, or map::end if all keys are considered to go before k.
		 */
		const_iterator lower_bound(const key_type &k) const
		{
			const_iterator it = begin();

			while (it != end())
			{
				if (!comp_(it->first, k))
					return it;
				it++;
			}
			return it;
		}

		/**
		 * @brief Returns an iterator pointing to the first element in the container whose key is considered to go after k.
		 * The function uses its internal comparison object (key_comp) to determine this, returning an iterator to the first element for which key_comp(k,element_key) would return true.
		 * If the map class is instantiated with the default comparison type (less), the function returns an iterator to the first element whose key is greater than k.
		 * A similar member function, lower_bound, has the same behavior as upper_bound, except in the case that the map contains an element with a key equivalent to k: In this case lower_bound returns an iterator pointing to that element, whereas upper_bound returns an iterator pointing to the next element.
		 * @param k Key to search for.
		 * @return An iterator to the the first element in the container whose key is considered to go after k, or map::end if no keys are considered to go after k.
		 */
		iterator upper_bound(const key_type &k)
		{
			iterator it = begin();

			while (it != end())
			{
				if (comp_(k, it->first))
					return it;
				it++;
			}
			return it;
		}

		/**
		 * @brief Returns an iterator pointing to the first element in the container whose key is considered to go after k.
		 * The function uses its internal comparison object (key_comp) to determine this, returning an iterator to the first element for which key_comp(k,element_key) would return true.
		 * If the map class is instantiated with the default comparison type (less), the function returns an iterator to the first element whose key is greater than k.
		 * A similar member function, lower_bound, has the same behavior as upper_bound, except in the case that the map contains an element with a key equivalent to k: In this case lower_bound returns an iterator pointing to that element, whereas upper_bound returns an iterator pointing to the next element.
		 * @param k Key to search for.
		 * @return An const iterator to the the first element in the container whose key is considered to go after k, or map::end if no keys are considered to go after k.
		 */
		const_iterator upper_bound(const key_type &k) const
		{
			const_iterator it = begin();

			while (it != end())
			{
				if (comp_(k, it->first))
					return it;
				it++;
			}
			return it;
		}

		// TODO equal range

	private:
		tree *_container;
		allocator_type _alloc;
		key_compare _comp;
		size_type _size;
	};

}

#endif