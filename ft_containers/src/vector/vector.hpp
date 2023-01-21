#ifndef vector_H
#define vector_H

#ifndef DEBUG
#define DEBUG 0
#endif

#include <iostream>
#include <memory>
#include <iterator>
#include <algorithm>

namespace ft
{

	template <class T, class Alloc = std::allocator<T>>
	class vector
	{
	public:
		// MEMBER TYPES
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		// typedef ft::random_access_iterator<value_type> iterator;
		// typedef ft::random_access_iterator<const value_type> const_iterator;
		// typedef ft::reverse_iterator<iterator> reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		// typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;

		// MEMBER FUNCTIONS

		/**
		 * @brief empty container constructor (default constructor)
		 *
		 * Constructs an empty container, with no elements.
		 * @param alloc
		 */
		explicit vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _start(NULL), _end(NULL), _endCapacity(NULL)
		{

			if (DEBUG)
				std::cout << "\e[0;33mDefault Constructor called of vector\e[0m" << std::endl;
		}

		/**
		 * @brief fill constructor
		 *
		 * Constructs a container with n elements. Each element is a copy of val.
		 * @param n
		 * @param val
		 * @param alloc
		 */
		explicit vector(
			size_type n,
			const value_type &val = value_type(),
			const allocator_type &alloc = allocator_type())
			: _alloc(alloc)
		{
			if (DEBUG)
				std::cout << "\e[0;33mFill Constructor called of vector\e[0m" << std::endl;
			// Reservamos la memoria necesaria
			_start = _alloc.allocate(n);
			// Indicamos donde termina la memoria
			_endCapacity = _start + n;
			// Indicamos que el final del vector es el mismo que el inicio
			_end = _start;
			// Recorremos las posiciones reservadas para almacenar la memoria e inicializar el valor
			for (size_type i = 0; i < n; i++)
			{
				_alloc.construct(_end, val);
				_end++;
			}
		}

		// TODO enable_if
		/**
		 * @brief  range constructor
		 * Constructs a container with as many elements as the range [first,last),
		 * with each element constructed from its corresponding element in that range, in the same order.
		 * @tparam InputIterator
		 * @param first
		 * @param last
		 * @param alloc
		 */
		template <class InputIterator>
		vector(
			InputIterator first,
			InputIterator last,
			const allocator_type &alloc = allocator_type())
			: _alloc(alloc)
		{
			if (DEBUG)
				std::cout << "\e[0;33mRange Constructor called of vector\e[0m" << std::endl;

			// TODO calcular la distancia
			n = 8;
			// Reservamos la memoria necesaria
			_start = _alloc.allocate(n);
			// Indicamos donde termina la memoria
			_endCapacity = _start + n;
			// Indicamos que el final del vector es el mismo que el inicio
			_end = _start;
			// Recorremos las posiciones reservadas para almacenar la memoria e inicializar el valor
			while (first != last)
			{
				_alloc.construct(_end, *first++);
				_end++;
			}
		}

		// TODO completar todos los valores
		/**
		 * @brief copy constructor
		 * Constructs a container with a copy of each of the elements in x, in the same order.
		 * @param x
		 */
		vector(const vector &x) : _alloc(x._alloc)
		{
			if (DEBUG)
				std::cout << "\e[0;33mCopy Constructor called of vector\e[0m" << std::endl;
		}

		// Destructor
		// TODO liberar memoria
		/**
		 * @brief Destroys the container object.
		 *
		 */
		~vector()
		{
			if (DEBUG)
				std::cout << "\e[0;31mDestructor called of vector\e[0m" << std::endl;
			// _alloc.deallocate(_start, )
		}

		/**
		 * @brief Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
		 *
		 * @param x
		 * @return vector&
		 */
		vector &operator=(const vector &x)
		{
			if (x == *this)
				return (*this);
			// TODO liberar la memoria y copiar la memoria nueva
			return (*this);
		}

		// ==============================================================
		// 							ITERATORS
		// ==============================================================

		/**
		 * @brief Returns an iterator pointing to the first element in the vector.
		 *
		 * @return iterator
		 */
		iterator begin()
		{
			return _start;
		}

		/**
		 * @brief Returns an const iterator pointing to the first element in the vector.
		 *
		 * @return const_iterator
		 */
		const_iterator cbegin() const
		{
			return _start;
		}

		/**
		 * @brief Returns an iterator referring to the past-the-end element in the vector container.
		 *
		 * @return iterator
		 */
		iterator end()
		{
			// TODO comprobar si esta vacio para retornar el begin
			return _end;
		}

		/**
		 * @brief Returns an const iterator referring to the past-the-end element in the vector container.
		 *
		 * @return const_iterator
		 */
		const_iterator cend() const
		{
			// TODO comprobar si esta vacio para retornar el begin
			return _end;
		}

		/**
		 * @brief Returns a reverse iterator pointing to the last element in the vector
		 *
		 * @return reverse_iterator
		 */
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		/**
		 * @brief Returns a reverse const iterator pointing to the last element in the vector
		 *
		 * @return const_reverse_iterator
		 */
		const_reverse_iterator crbegin() const
		{
			return reverse_iterator(end());
		}

		/**
		 * @brief Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector
		 *
		 * @return reverse_iterator
		 */
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		/**
		 * @brief Returns a reverse const iterator pointing to the theoretical element preceding the first element in the vector
		 *
		 * @return const_reverse_iterator
		 */
		const_reverse_iterator crend() const
		{
			return reverse_iterator(begin());
		}

		// ==============================================================
		// 							CAPACITY
		// ==============================================================

		/**
		 * @brief Returns the number of elements in the vector.
		 *
		 * @return size_type
		 */
		size_type size() const
		{
			return _end - _start;
		}

		/**
		 * @brief Returns the maximum number of elements that the vector can hold.
		 *
		 * @return size_type
		 */
		size_type max_size() const
		{
			return allocator_type().max_size();
		}

		/**
		 * @brief Resizes the container so that it contains n elements.
		 * If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
		 * If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n. If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
		 * If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
		 * Notice that this function changes the actual content of the container by inserting or erasing elements from it.

		 * @param n
		 * @param val
		 */
		void resize(size_type n, value_type val = value_type())
		{
			// Comprobamos si el nuevo size es mayor al maximo y lanzamos un error
			if (n > max_size())
				throw std::length_error("vector::resize");
			// Comprobamos si el nuevo size es inferior al size anterior
			if (n < size())
			{
				// Liberamos toda la memoria que ya no necesitamos
				while (size() > n)
				{
					--_end;
					_alloc.destroy(_end);
				}
				return;
			}
			// Reservamos nueva memoria en caso de que el size sea mayor al anterior
			insert(end(), n - size(), val);
		}

		/**
		 * @brief Returns the size of the storage space currently allocated for the vector, expressed in terms of elements.
		 * This capacity is not necessarily equal to the vector size. It can be equal or greater, with the extra space allowing to accommodate for growth without the need to reallocate on each insertion.
		 * Notice that this capacity does not suppose a limit on the size of the vector. When this capacity is exhausted and more is needed, it is automatically expanded by the container (reallocating it storage space). The theoretical limit on the size of a vector is given by member max_size.
		 * The capacity of a vector can be explicitly altered by calling member vector::reserve.
		 * @return size_type
		 */
		size_type capacity() const
		{
			return _endCapacity - _start;
		}

		/**
		 * @brief Returns whether the vector is empty (i.e. whether its size is 0).
		 * This function does not modify the container in any way. To clear the content of a vector, see vector::clear.
		 * @return true
		 * @return false
		 */
		bool empty() const
		{
			return size() == 0;
		}

		/**
		 * @brief Requests that the vector capacity be at least enough to contain n elements.
		 * If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).
		 * In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
		 * This function has no effect on the vector size and cannot alter its elements.
		 * @param n
		 */
		void reserve(size_type n)
		{
			if (n > max_size())
				throw(std::length_error("vector::reserve"));
			if (n > capacity())
			{
				pointer oldStart = _start;
				pointer oldEnd = _end;
				size_type oldSize = size();
				size_type oldCapacity = capacity();

				_start = _alloc.allocate(n);
				_endCapacity = _start + n;
				_end = _start;
				while (oldStart != oldEnd)
				{
					_alloc.construct(_end, *oldStart);
					_end++;
					oldStart++;
				}
				_alloc.deallocate(oldStart - oldSize, oldCapacity);
			}
		}

		// TODO comprobar si hay que hacerlo
		void shrink_to_fit()
		{
		}

		// ==============================================================
		// 							ELEMENT ACCESS
		// ==============================================================

		/**
		 * @brief Returns a reference to the element at position n in the vector container.

		 *
		 * @param n
		 * @return reference
		 */
		reference operator[](size_type n)
		{
			return *(_start + n);
		}

		/**
		 * @brief Returns a const reference to the element at position n in the vector container.

		 *
		 * @param n
		 * @return const_reference
		 */
		const_reference operator[](size_type n) const
		{
			return *(_start + n);
		}

		/**
		 * @brief Returns a reference to the element at position n in the vector.
		 * The function automatically checks whether n is within the bounds of valid elements in the vector, throwing an out_of_range exception if it is not
		 * This is in contrast with member operator[], that does not check against bounds.
		 * @param n
		 * @return reference
		 */
		reference at(size_type n)
		{
			// TODO comprobar si n se encuentra dentro del rango del vector
			return *this[n];
		}

		/**
		 * @brief Returns a const reference to the element at position n in the vector.
		 * The function automatically checks whether n is within the bounds of valid elements in the vector, throwing an out_of_range exception if it is not
		 * This is in contrast with member operator[], that does not check against bounds.
		 * @param n
		 * @return reference
		 */

		const_reference at(size_type n) const
		{
			// TODO comprobar si n se encuentra dentro del rango del vector
			return *this[n];
		}

		/**
		 * @brief Returns a reference to the first element in the vector.
		 * Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.
		 * Calling this function on an empty container causes undefined behavior.
		 * @return reference
		 */
		reference front()
		{

			return *_start;
		}

		/**
		 * @brief Returns a const reference to the first element in the vector.
		 * Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.
		 * Calling this function on an empty container causes undefined behavior.
		 * @return reference
		 */

		const_reference front() const
		{
			return *_start;
		}

		/**
		 * @brief Returns a reference to the last element in the vector.
		 * Unlike member vector::end, which returns an iterator just past this element, this function returns a direct reference.
		 * Calling this function on an empty container causes undefined behavior.
		 * @return reference
		 */
		reference back()
		{
			return *(_end - 1);
		}

		/**
		 * @brief Returns a const reference to the last element in the vector.
		 * Unlike member vector::end, which returns an iterator just past this element, this function returns a direct reference.
		 * Calling this function on an empty container causes undefined behavior.
		 * @return reference
		 */

		const_reference back() const
		{
			return *(_end - 1);
		}

		// TODO comprobar si son necesarias
		value_type *data() noexcept {}
		const value_type *data() const noexcept {}

		// ==============================================================
		// 							MODIFIERS
		// ==============================================================

		// TODO enable_if
		/**
		 * @brief Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		 * the new contents are elements constructed from each of the elements in the range between first and last, in the same order.
		 * @tparam InputIterator
		 * @param first
		 * @param last
		 */
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
		}

		/**
		 * @brief Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		 *  the new contents are n elements, each initialized to a copy of val.
		 * @param n
		 * @param val
		 */
		void assign(size_type n, const value_type &val)
		{
		}

		/**
		 * @brief Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
		 * This effectively increases the container size by one, which causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
		 * @param val Value to be copied (or moved) to the new element.
		 */
		void push_back(const value_type &val)
		{
			if (_end == _endCapacity)
			{
				int newCapacity = (size() > 0) ? (int)(size() * 2) : 1;
				reserve(newCapacity);
			}
			_alloc.construct(_end, val);
			_end++;
		}

		/**
		 * @brief Removes the last element in the vector, effectively reducing the container size by one.
		 * This destroys the removed element.
		 */
		void pop_back()
		{
			_alloc.destroy(&back());
			_end--;
		}

		/**
		 * @brief The vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.
		 * This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
		 * Because vectors use an array as their underlying storage, inserting elements in positions other than the vector end causes the container to relocate all the elements that were after position to their new positions. This is generally an inefficient operation compared to the one performed for the same operation by other kinds of sequence containers (such as list or forward_list).
		 * (single element)
		 * @param position Position in the vector where the new elements are inserted.
		 * @param val Value to be copied (or moved) to the inserted elements.
		 * @return An iterator that points to the first of the newly inserted elements.
		 */
		iterator insert(iterator position, const value_type &val)
		{
		}

		/**
		 * @brief The vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.
		 * This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
		 * Because vectors use an array as their underlying storage, inserting elements in positions other than the vector end causes the container to relocate all the elements that were after position to their new positions. This is generally an inefficient operation compared to the one performed for the same operation by other kinds of sequence containers (such as list or forward_list).
		 * (fill)
		 * @param position Position in the vector where the new elements are inserted.
		 * @param n Number of elements to insert. Each element is initialized to a copy of val.
		 * @param val Value to be copied (or moved) to the inserted elements.
		 */
		void insert(iterator position, size_type n, const value_type &val)
		{
		}

		/**
		 * @brief The vector is extended by inserting new elements before the element at the specified position, effectively increasing the container size by the number of elements inserted.
		 * This causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
		 * Because vectors use an array as their underlying storage, inserting elements in positions other than the vector end causes the container to relocate all the elements that were after position to their new positions. This is generally an inefficient operation compared to the one performed for the same operation by other kinds of sequence containers (such as list or forward_list).
		 * (range)
		 * @tparam InputIterator
		 * @param position Position in the vector where the new elements are inserted.
		 * @param first Iterators specifying a range of elements.
		 * @param last Iterators specifying a range of elements.
		 */
		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
		}

		/**
		 * @brief Removes from the vector either a single element (position) or a range of elements ([first,last)).
		 * This effectively reduces the container size by the number of elements removed, which are destroyed.
		 * Because vectors use an array as their underlying storage, erasing elements in positions other than the vector end causes the container to relocate all the elements after the segment erased to their new positions. This is generally an inefficient operation compared to the one performed for the same operation by other kinds of sequence containers (such as list or forward_list).
		 * @param position Iterator pointing to a single element to be removed from the vector.
		 * @return An iterator pointing to the new location of the element that followed the last element erased by the function call. This is the container end if the operation erased the last element in the sequence.
		 */
		iterator erase(iterator position)
		{
		}

		/**
		 * @brief Removes from the vector either a single element (position) or a range of elements ([first,last)).
		 * This effectively reduces the container size by the number of elements removed, which are destroyed.
		 * Because vectors use an array as their underlying storage, erasing elements in positions other than the vector end causes the container to relocate all the elements after the segment erased to their new positions. This is generally an inefficient operation compared to the one performed for the same operation by other kinds of sequence containers (such as list or forward_list).
		 * @param first Iterators specifying a range within the vector] to be removed: [first,last). i.e., the range includes all the elements between first and last,
		 * @param last Iterators specifying a range within the vector] to be removed: [first,last). i.e., the range includes all the elements between first and last,
		 * @return An iterator pointing to the new location of the element that followed the last element erased by the function call. This is the container end if the operation erased the last element in the sequence.
		 */
		iterator erase(iterator first, iterator last)
		{
		}

		/**
		 * @brief Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.
		 * After the call to this member function, the elements in this container are those which were in x before the call, and the elements of x are those which were in this. All iterators, references and pointers remain valid for the swapped objects.
		 * Notice that a non-member function exists with the same name, swap, overloading that algorithm with an optimization that behaves like this member function.
		 * @param xAnother vector container of the same type (i.e., instantiated with the same template parameters, T and Alloc) whose content is swapped with that of this container.
		 */
		void swap(vector &x)
		{
			if (x == *this)
				return;
			// Guardamos los valores del vector x
			pointer xStart = x._start;
			pointer xEnd = x._end;
			pointer xEndCapacity = x._endCapacity;
			allocator_type xAlloc = x._alloc;
			// Asignamos al vector x los valores del vector
			x._start = _start;
			x._end = _end;
			x._end_capacity = _end_capacity;
			x._alloc = _alloc;
			// Asignamos al vector los valores del vector x
			_start = xStart;
			_end = xEnd;
			_endCapacity = xEndCapacity;
			_alloc = xAlloc;
		}

		/**
		 * @brief Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		 * A reallocation is not guaranteed to happen, and the vector capacity is not guaranteed to change due to calling this function. A typical alternative that forces a reallocation is to use swap:
		 */
		void clear()
		{
			size_type oldSize = size();
			for (size_type i = 0; i < oldSize; i++)
			{
				_end--;
				_alloc.destroy(_end);
			}
		}

		// TODO comprobar si es necesaria
		template <class... Args>
		iterator emplace(const_iterator position, Args &&...args) {}

	private:
		allocator_type _alloc;
		pointer _start;
		pointer _end;
		pointer _endCapacity;
	};

}
#endif