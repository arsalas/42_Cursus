#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <memory>
#include <iterator>
#include <algorithm>
#include <cstddef> // ptrdiff_t
#include <sstream> // ostring

#include "vector_iterator.hpp"
#include "reverse_iterator.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"
#include "debug.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> >
	class vector
	{
	public:
		// ==============================================================
		// 							MEMBER TYPES
		// ==============================================================
		typedef T value_type;
		typedef Alloc allocator_type;

		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;

		typedef ft::vector_iterator<T, false> iterator;
		typedef ft::vector_iterator<T, true> const_iterator;
		typedef ft::reverse_iterator<iterator> reverse_iterator;
		typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		// TODO comprobar si es correcto
		// typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
		// typedef typename allocator_type::size_type size_type;
		typedef std::ptrdiff_t difference_type;
		typedef std::size_t size_type;

		// ==============================================================
		// 							MEMBER FUNCTIONS
		// ==============================================================

		/**
		 * @brief empty container constructor (default constructor)
		 *
		 * Constructs an empty container, with no elements.
		 * @param alloc
		 */
		explicit vector(const allocator_type &alloc = allocator_type())
			: _alloc(alloc), _vector(NULL), _size(0), _capacity(0)
		{
			printDebug("\e[0;33mDefault Constructor called of vector\e[0m\n");
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
			: _alloc(alloc), _vector(NULL), _size(0), _capacity(0)
		{
			printDebug("\e[0;33mFill Constructor called of vector\e[0m\n");
			// Insertamos los valores en las n posiciones
			insert(begin(), n, val);
		}

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
			const allocator_type &alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
			: _alloc(alloc), _vector(NULL), _size(0), _capacity(0)
		{
			printDebug("\e[0;33mRange Constructor called of vector\e[0m\n");
			// Insertamos el rango de valores que nos pasan en el contructor con los iteradores
			insert(begin(), first, last);
		}

		/**
		 * @brief copy constructor
		 * Constructs a container with a copy of each of the elements in x, in the same order.
		 * @param x
		 */
		vector(const vector &x) : _alloc(x._alloc), _vector(NULL), _size(0), _capacity(0)
		{
			printDebug("\e[0;33mCopy Constructor called of vector\e[0m\n");
			// Asignamos todos los valores del vector de copia
			assign(x.begin(), x.end());
		}

		// Destructor
		/**
		 * @brief Destroys the container object.
		 *
		 */
		~vector()
		{
			printDebug("\e[0;31mDestructor called of vector\e[0m\n");
			clear();
			_alloc.deallocate(_vector, _capacity);
		}

		/**
		 * @brief Assigns new contents to the container, replacing its current contents, and modifying its size accordingly.
		 *
		 * @param x
		 * @return vector&
		 */
		vector &operator=(const vector &x)
		{
			if (&x == this)
				return *this;
			// TODO comprobar si hay que liberar la memoria previamente
			assign(x.begin(), x.end());
			return *this;
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
			return iterator(_vector);
		}

		/**
		 * @brief Returns an const iterator pointing to the first element in the vector.
		 *
		 * @return const_iterator
		 */
		const_iterator begin() const
		{
			return const_iterator(_vector);
		}

		/**
		 * @brief Returns an iterator referring to the past-the-end element in the vector container.
		 *
		 * @return iterator
		 */
		iterator end()
		{
			return iterator(_vector + _size);
		}

		/**
		 * @brief Returns an const iterator referring to the past-the-end element in the vector container.
		 *
		 * @return const_iterator
		 */
		const_iterator end() const
		{
			return const_iterator(_vector + _size);
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
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
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
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
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
			return _size;
		}

		/**
		 * @brief Returns the maximum number of elements that the vector can hold.
		 *
		 * @return size_type
		 */
		size_type max_size() const
		{
			return _alloc.max_size();
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
			// Comprobamos si hay que reservar nueva memoria
			if (n > _capacity)
			{
				// Si la capacidad es 0 reservamos n
				if (_capacity == 0)
					reserve(n);
				// Comprobamos si con el doble del size actual tenemos suficiente memoria
				else if (_size * 2 >= n)
					reserve(_size * 2);
				// En caso de no tener suficiente memoria con el doble reservamos n
				else
					reserve(n);
			}
			// Mientras el size no llegue al nuevo vamos insertando val
			while (_size < n)
			{
				push_back(val);
			}
			// Vamos eliminado los valores que pasan del nuevo size
			while (_size > n)
			{
				pop_back();
			};
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
			return _capacity;
		}

		/**
		 * @brief Returns whether the vector is empty (i.e. whether its size is 0).
		 * This function does not modify the container in any way. To clear the content of a vector, see vector::clear.
		 * @return true
		 * @return false
		 */
		bool empty() const
		{
			return _size == 0;
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
			// Comprovamos si el nuevo size pasa del maximo
			if (n > max_size())
				throw(std::length_error("vector::reserve"));
			// Cortamos la funcion si tenemos capacidad suficiente en el contenedor
			if (n < _capacity)
				return;

			// Creamos un nuevo allocator con el nuevo size
			value_type *newContainer = _alloc.allocate(n);
			// Recorremos el contenedor actual
			for (size_type i = 0; i < _size; i++)
			{
				// Copiamos el valor al nuevo contenedor
				_alloc.construct(&newContainer[i], _vector[i]);
				// Liberamos la memoria que ya no necesitamos
				_alloc.destroy(&_vector[i]);
			}
			// Liberamos el contenedor
			_alloc.deallocate(_vector, _capacity);
			// Indicamos la nueva capacidad del contenedor
			_capacity = n;
			// Guardamos el nuevo contenedor
			_vector = newContainer;
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
			return _vector[n];
			// TODO Comprobar si funciona igual
			// return *(_container + n);
		}

		/**
		 * @brief Returns a const reference to the element at position n in the vector container.

		 *
		 * @param n
		 * @return const_reference
		 */
		const_reference operator[](size_type n) const
		{
			return _vector[n];
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
			if (n >= _size)
			{
				// TODO comprobar si es correcto
				std::stringstream ss;
				ss << "vector";
				throw std::out_of_range(ss.str().c_str());
			}
			return _vector[n];
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
			if (n >= _size)
			{
				// TODO comprobar si es correcto
				std::stringstream ss;
				ss << "vector";
				throw std::out_of_range(ss.str().c_str());
			}
			return _vector[n];
		}

		/**
		 * @brief Returns a reference to the first element in the vector.
		 * Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.
		 * Calling this function on an empty container causes undefined behavior.
		 * @return reference
		 */
		reference front()
		{

			return _vector[0];
		}

		/**
		 * @brief Returns a const reference to the first element in the vector.
		 * Unlike member vector::begin, which returns an iterator to this same element, this function returns a direct reference.
		 * Calling this function on an empty container causes undefined behavior.
		 * @return reference
		 */

		const_reference front() const
		{
			return _vector[0];
		}

		/**
		 * @brief Returns a reference to the last element in the vector.
		 * Unlike member vector::end, which returns an iterator just past this element, this function returns a direct reference.
		 * Calling this function on an empty container causes undefined behavior.
		 * @return reference
		 */
		reference back()
		{
			return _vector[_size - 1];
		}

		/**
		 * @brief Returns a const reference to the last element in the vector.
		 * Unlike member vector::end, which returns an iterator just past this element, this function returns a direct reference.
		 * Calling this function on an empty container causes undefined behavior.
		 * @return reference
		 */

		const_reference back() const
		{
			return _vector[_size - 1];
		}

		// TODO comprobar si son necesarias
		// value_type *data() noexcept {}
		// const value_type *data() const noexcept {}

		// ==============================================================
		// 							MODIFIERS
		// ==============================================================

		/**
		 * @brief Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		 * the new contents are elements constructed from each of the elements in the range between first and last, in the same order.
		 * @tparam InputIterator
		 * @param first
		 * @param last
		 */
		template <class InputIterator>
		void assign(
			InputIterator first,
			InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			// Vaciamos el contenedor
			clear();
			// Guardamos en un iterador el primer elemento del contenedor
			InputIterator it = first;
			// Guardaremos la cantidad de posiciones que se tienen que resservar
			difference_type n = 0;
			// Recorremos el contenedor
			while (it != last)
			{
				n++;
				it++;
			}
			// Reservamos la memoria necesaria
			reserve(n);
			// Insertamos todos los elementos del contenedor
			insert(begin(), first, last);
		}

		/**
		 * @brief Assigns new contents to the vector, replacing its current contents, and modifying its size accordingly.
		 *  the new contents are n elements, each initialized to a copy of val.
		 * @param n
		 * @param val
		 */
		void assign(size_type n, const value_type &val)
		{
			// Vaciamos el contenedor
			clear();
			// Reservamos la nueva memoria
			reserve(n);
			// Insertamos val en todas las posiciones del contenedor
			insert(begin(), n, val);
		}

		/**
		 * @brief Adds a new element at the end of the vector, after its current last element. The content of val is copied (or moved) to the new element.
		 * This effectively increases the container size by one, which causes an automatic reallocation of the allocated storage space if -and only if- the new vector size surpasses the current vector capacity.
		 * @param val Value to be copied (or moved) to the new element.
		 */
		void push_back(const value_type &val)
		{
			// Comprobamos si el vector no tiene capacidad para un nuevo elemento
			if (_size + 1 > _capacity)
			{
				// En caso de que la capacidad del vector sea 0 reservamos solo un elemento
				if (_capacity == 0)
					reserve(1);
				// En caso contrario doblamos la capacidad del vector
				else
					reserve(_capacity * 2);
			}
			// Creamos el nuevo elemento al final del vector
			_alloc.construct(&_vector[_size], val);
			// Incrementamos el size del vector
			_size++;
		}

		/**
		 * @brief Removes the last element in the vector, effectively reducing the container size by one.
		 * This destroys the removed element.
		 */
		void pop_back()
		{
			// Comprobamos si el size es mayor a 0
			if (_size > 0)
			{
				// Destruimos el ultimo elemento del vector
				_alloc.destroy(&_vector[_size - 1]);
				// Reducimos el size del vector
				_size--;
			}
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
			// Obtenemos el indice donde tenemos que hacer el insert
			size_type index = position - begin();
			// Comprobamos si no tenemos suficiente capacidad
			if (_capacity < _size + 1)
			{
				// Si la capacidad es 0 reservamos 1 posicion
				if (_capacity == 0)
					reserve(1);
				// En caso contrario reservamos el doble de la capacidad actual
				else
					reserve(_capacity * 2);
			}
			// Incrementamos el size del vector
			_size++;
			// Si el indice es inferior al size tenemos que desplazar los elementos una posicion
			if (index < _size)
			{
				for (size_type i = _size - 1; i > index; i--)
				{
					_alloc.construct(&_vector[i], _vector[i - 1]);
					_alloc.destroy(&_vector[i - 1]);
				}
			}
			// Guardamos el val en la posicion
			_alloc.construct(&_vector[index], val);
			// Retornamos un iterador a la posicion del nuevo elemento
			return iterator(&_vector[index]);
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
			// Obtenemos el indice donde tenemos que hacer el insert
			size_type index = position - begin();

			// Comprobamos si no tiene suficiente capacidad para guradar el elemento
			if (_capacity < _size + n)
			{
				// Si la capacidad es 0 reservamos n
				if (_capacity == 0)
					reserve(n);
				// Reservamos el doble de la capacidad actual si es suficiente
				else if (_size * 2 >= _size + n)
					reserve(_size * 2);
				// En caso contrario reservamos la capacidad necesaria con n
				else
					reserve(_size + n);
			}
			// Movemos los elementos que pasan de el numero de registros que vamos a insertar
			for (size_type i = n + _size - 1; i > index + n - 1; i--)
			{
				_alloc.construct(&_vector[i], _vector[i - n]);
				_alloc.destroy(&_vector[i - n]);
			}
			// Creamos los nuevos elementos del vector
			for (size_type i = index; i < index + n; i++)
			{
				_alloc.construct(&_vector[i], val);
				_size++;
			}
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
		void insert(
			iterator position,
			InputIterator first,
			InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			// Calculamos el indice donde se empiezan a insertar los elementos
			size_type offset = position - begin();
			// Creamos un iterador en la primera posicion del elemento
			InputIterator it = first;
			// Creamos una variable que nos dira cuantas posiciones hay que crear
			difference_type n = 0;
			// Recorremos el iterador para comprobar cuantos elementos hay
			while (it != last)
			{
				n++;
				it++;
			}
			// Comprobamos si hay que reservar memoria
			if (_capacity < _size + n)
			{
				// Si la capacidad del vector es 0 reservamos b
				if (_capacity == 0)
					reserve(n);
				// Comprobamos si tenemos suficiente memoria con el doble de la capacidad actual
				else if (_size * 2 >= _size + n)
					reserve(_size * 2);
				// En caso contrario reservamos n
				else
					reserve(_size + n);
			}
			// Desplazamos los elementos que van despues de los que vamos a insertar
			for (size_type i = n + _size - 1; i > offset + n - 1; i--)
			{
				_alloc.construct(&_vector[i], _vector[i - n]);
				_alloc.destroy(&_vector[i - n]);
			}
			// Recorremos el iterador para insertar los nuevos elementos
			for (size_type i = offset; i < offset + n; i++)
			{
				_alloc.construct(&_vector[i], *first);
				first++;
				_size++;
			}
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
			// Obtenemos el indice de la posicion que queremos borrar
			size_type index = position - begin();
			// Destruimos la posicion del vector indicada
			_alloc.destroy(&_vector[index]);
			// Disminuimos el size del vector
			_size--;
			// Desplazamos los elementos que quedan despues del elemento borrado
			for (size_type i = index; i < _size; i++)
			{
				_alloc.construct(&_vector[i], _vector[i + 1]);
				_alloc.destroy(&_vector[i + 1]);
			}
			// Retornamos el iterador apuntando al indice del elemento borrado
			return iterator(&_vector[index]);
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
			// Calculamos la posicion inicial del vector a borrar
			size_type start = first - begin();
			// Cantidad de elementos a borrar
			difference_type offset = last - first;
			// Si el primer elemento y el ultimo es el mismo no hay que borrar nada
			if (first == last)
       			 return iterator(first);
			// Recorremos las posiciones a borrar
			for (iterator it = first; it != last; it++)
			{
        		_alloc.destroy(&(*it));
			}
			// Restamos al size todos los elementos que hemos borrado
			_size -= offset;
			// Si la posicion inicial es mas pequena que el size desplazamos la memoria al inicio
			if (start < _size)
			{
        		for (size_type i = start; i < _size; i++)
				{
          			_alloc.construct(&_vector[i], _vector[i + offset]);
          			_alloc.destroy(&_vector[i + offset]);
        		}
      		}
			// Retornamos un iterador a la posicion inicial
 			return iterator(&_vector[start]);
		}

		/**
		 * @brief Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.
		 * After the call to this member function, the elements in this container are those which were in x before the call, and the elements of x are those which were in this. All iterators, references and pointers remain valid for the swapped objects.
		 * Notice that a non-member function exists with the same name, swap, overloading that algorithm with an optimization that behaves like this member function.
		 * @param xAnother vector container of the same type (i.e., instantiated with the same template parameters, T and Alloc) whose content is swapped with that of this container.
		 */
		void swap(vector &x)
		{
			// Guardamos en una variable los valores del vector x
			value_type *xVector = x._vector;
			size_type xSize = x._size;
			size_type xCapacity = x._capacity;
			// Intercambiamos los valores entre los vectores
			x._vector = _vector;
			x._size = _size;
			x._capacity = _capacity;
			_vector = xVector;
			_size = xSize;
			_capacity = xCapacity;
		}

		/**
		 * @brief Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		 * A reallocation is not guaranteed to happen, and the vector capacity is not guaranteed to change due to calling this function. A typical alternative that forces a reallocation is to use swap:
		 */
		void clear()
		{
			erase(begin(), end());
		}

		// TODO comprobar si es necesaria
		// template <class... Args>
		// iterator emplace(const_iterator position, Args &&...args) {}

	private:
		allocator_type _alloc;
		value_type *_vector;
		size_type _size;
		size_type _capacity;
	};
}
#endif