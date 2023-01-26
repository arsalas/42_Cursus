#ifndef MAP_H
#define MAP_H

#ifndef DEBUG
#define DEBUG 0
#endif

#include <memory>

#include "pair.hpp"
#include "utils.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

#include "map_iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template <class Key, class T, class Compare = ft::less<Key>,
			  class Alloc = std::allocator<ft::pair<const Key, T> > >
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
			: _alloc(alloc), _comp(comp), _size(0)
		{
			// El nodo principal no tiene parent, left y right apuntan al mismo nodo
			_map = _alloc_node.allocate(1);
			_map->_left = _map;
			_map->_right = _map;
			_map->_parent = NULL;
			// Reservamos la memoria para el nodo
			_alloc.construct(&_map->_pair, value_type());
			if (DEBUG)
				std::cout << "\e[0;33mDefault Constructor called of map\e[0m" << std::endl;

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
			: _alloc(alloc), _comp(comp), _size(0)
		{
			// El nodo principal no tiene parent, left y right apuntan al mismo nodo
			_map = _alloc_node.allocate(1);
			_map->_left = _map;
			_map->_right = _map;
			_map->_parent = NULL;
			// Reservamos la memoria para el nodo
			_alloc.construct(&_map->_pair, value_type());
			// Insertamos todos los nodos que recive el constructor
			insert(first, last);
			if (DEBUG)
				std::cout << "\e[0;33mElements Constructor called of map\e[0m" << std::endl;
		}

		/**
		 * @brief Constructs a container with a copy of each of the elements in x.
		 *
		 * @param x Another map object of the same type (with the same class template arguments Key, T, Compare and Alloc), whose contents are either copied or acquired.
		 */
		map(const map &x) :  _alloc(x._alloc), _comp(x._comp),  _size(0)
		{
			// El nodo principal no tiene parent, left y right apuntan al mismo nodo
			_map = _alloc_node.allocate(1);
			_map->_left = _map;
			_map->_right = _map;
			_map->_parent = NULL;
			// Reservamos la memoria para el nodo
			_alloc.construct(&_map->_pair, value_type());
			// Insertamos todos los nodos que tiene el map que queremos copiar
			insert(x.begin(), x.end());
			if (DEBUG)
				std::cout << "\e[0;33mCopy Constructor called of map\e[0m" << std::endl;
		}

		/**
		 * @brief Destroys the container object.
		 *
		 */
		~map()
		{
			// Destruye todos los nodos del map
			clear();
			// Libera la memoria reservada
			_alloc.destroy(&_map->_pair);
			_alloc_node.deallocate(_map, 1);
			if (DEBUG)
				std::cout << "\e[0;31mDestructor called of map\e[0m" << std::endl;
		}

		/**
		 * @brief Copies all the elements from x into the container, changing its size accordingly.
		 * The container preserves its current allocator, which is used to allocate additional storage if needed.
		 * @param x A map object of the same type (i.e., with the same template parameters, key, T, Compare and Alloc).
		 * @return *this
		 */
		map &operator=(const map &x)
		{
			// Borramos todos los nodos del map
			clear();
			// Copiamos los nodos del map que queremos igualar
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
			return iterator(getLeft());
		}
		/**
		 * @brief Returns an iterator referring to the first element in the map container.
		 * Because map containers keep their elements ordered at all times, begin points to the element that goes first following the container's sorting criterion.
		 * If the container is empty, the returned iterator value shall not be dereferenced.
		 * @return An iterator to the first element in the container.
		 */
		const_iterator begin() const
		{
			return const_iterator(getLeft());
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
			return iterator(_map);
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
			return const_iterator(_map);
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
			return _size == 0;
		}

		/**
		 * @brief Returns the number of elements in the map container.
		 *
		 * @return The number of elements in the container.
		 */
		size_type size() const
		{
			return _size;
		}

		/**
		 * @brief Returns the maximum number of elements that the map container can hold.
		 * This is the maximum potential size the container can reach due to known system or library implementation limitations, but the container is by no means guaranteed to be able to reach that size: it can still fail to allocate storage at any point before that size is reached.
		 * @return The maximum number of elements a map container can hold as content.
		 */
		size_type max_size() const
		{
			return _alloc_node.max_size();
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
			// TODO creo que esto no esta bien
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
		mapped_type &at(const key_type &k)
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
			// Comprueba si existe la key
			tree *exist = existKey(getRoot(), val.first);
			// Si existe retorna el nodo
			if (exist)
				return ft::make_pair(iterator(exist), false);
			// Incrementa el size del map
			_size++;
			// Inserta un nuevo nodo con el pair dado
			return ft::make_pair(iterator(insertNode(_map, _comp, val)), true);
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
			// Comprueba si existe la key
			tree *exist = existKey(getRoot(), val.first);
			// Si existe retorna el nodo
			if (exist)
				return iterator(exist);
			// Incrementa el size del map
			_size++;
			// Inserta un nuevo nodo con el pair dado
			return iterator(insertNode(_map, _comp, val));
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
			// Recorre los iteradores insertando los nodos
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
			// Guardamos una referencia del inicio que queremos borrar
			tree *current = position._pointer;
			tree *tmp = NULL;
			// Si tiene un nodo a la izquierda (menor)
			if (current->_left)
			{
				tmp = current->_left;
				// Mientras el nodo tenga un child a la derecha(mayor) no desplazamos hacia la derecha
				while (tmp->_right)
					tmp = tmp->_right;
				// Comprobamos si hemos llegado al final mirando si el child es el mismo nodo
				if (tmp->_parent->_right == tmp)
				{
					// Comprobamos si el ultimo nodo tiene child a la izquierda
					if (tmp->_left)
					{
						// Hazemos que el nodo de la izquierda se el child a la derecha del parent
						tmp->_parent->_right = tmp->_left;
						// El child de la izquierda es el mismo nodo para indicar que no tiene mas childs
						tmp->_left->_parent = tmp->_parent;
					}
					else
						tmp->_parent->_right = NULL;
				}
				tmp->_right = current->_right;
				if (current->_right)
					current->_right->_parent = tmp;
				if (current->_left != tmp)
					tmp->_left = current->_left;
				if (current->_left)
					current->_left->_parent = tmp;
				tmp->_parent = current->_parent;
			}
			// Si tiene un nodo a la derecha (mayor)
			else if (current->_right)
			{
				tmp = current->_right;
				tmp->_parent = current->_parent;
			}
			if (current->_parent->_left == current)
				current->_parent->_left = tmp;
			else
				current->_parent->_right = tmp;
			if (current == getRoot())
				_map->_parent = tmp;
			_alloc.destroy(&current->_pair);
			_alloc_node.deallocate(current, 1);
			_size--;
			setLeftRight();
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
			// Recorre el arbol binario
			while (it != end())
			{
				if (!_comp(it->first, k) && !_comp(k, it->first))
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
			// Recorre los iteradores y borra el nodo
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

			size_tmp = _size;
			_size = x._size;
			x._size = size_tmp;

			tmp = _map;
			_map = x._map;
			x._map = tmp;
		}

		/**
		 * @brief Removes all elements from the map container (which are destroyed), leaving the container with a size of 0.
		 */
		void clear()
		{
			// Borra todo el arbol binario
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
			// Comprueba si existe la key
			tree *found = existKey(getRoot(), k);
			// Si encuentra la key retorna un iterador a ese nodo
			if (found)
				return iterator(found);
			// En caso de no encontrarla retora un iterador al final del arbol
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
			// Comprueba si existe la key
			tree *found = existKey(getRoot(), k);
			// Si encuentra la key retorna un iterador constante a ese nodo
			if (found)
				return const_iterator(found);
			// En caso de no encontrarla retora un iterador constante al final del arbol
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
			return countKey(getRoot(), k);
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

			// Recorre el arbol hasta encontrar la key
			while (it != end())
			{
				if (!_comp(it->first, k))
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
			// Recorre el arbol hasta encontrar la key
			while (it != end())
			{
				if (!_comp(it->first, k))
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
				if (_comp(k, it->first))
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
				if (_comp(k, it->first))
					return it;
				it++;
			}
			return it;
		}

		// TODO equal range

	private:

		// ==============================================================
		// 							TREE
		// ==============================================================

		typedef Tree<value_type> tree;

		/**
		 * @brief Comprueba si existe una key y retorna el nodo de esta
		 *
		 * @param root
		 * @param key
		 * @return tree*
		 */
		// TODO intentar mejorar la velocidad
		tree *existKey(tree *root, key_type key) const
		{
			// Obtiene el root del nodo
			tree *found = getRoot();
			if (!root)
				return NULL;
			// Se desplaza a la izquierda en el arbol
			found = existKey(root->_left, key);
			if (!_comp(root->_pair.first, key) && !_comp(key, root->_pair.first))
				found = root;
			// Si no encuentra la key hacia la izquierda se desplaza a la derecha
			if (!found)
				found = existKey(root->_right, key);
			return found;
		}

		/**
		 * @brief Comprueba si existe la key en el arbol
		 *
		 * @param root
		 * @param key
		 * @return size_type
		 */
		size_type countKey(tree *root, key_type key) const
		{
			if (!root)
				return 0;
			if (!_comp(root->_pair.first, key) && !_comp(key, root->_pair.first))
				return 1;
			return countKey(root->_left, key) + countKey(root->_right, key);
		}

		/**
		 * @brief Encuentra el nodo mayor y menor
		 *
		 */
		void setLeftRight()
		{
			tree *tmp = getRoot();

			if (!tmp)
			{
				_map->_left = _map;
				_map->_right = _map;
				return;
			}
			// Recorre el arbol hacia la izquierda
			while (tmp && tmp->_left)
				tmp = tmp->_left;
			_map->_left = tmp;

			tmp = getRoot();
			// Recorre el arbol hacia la derecha
			while (tmp && tmp->_right)
				tmp = tmp->_right;
			_map->_right = tmp;
		}

		tree *insertNode(tree *node, key_compare comp, value_type pair)
		{
			// Miramos si el nodo que nos pasan es el map
			if (node == _map)
			{
				// Comprobamos si no tiene un nodo padre
				if (!node->_parent)
				{
					// Reservamos memoria
					node->_parent = _alloc_node.allocate(1);
					node->_parent->_left = NULL;
					node->_parent->_right = NULL;
					node->_parent->_parent = node;
					_alloc.construct(&node->_parent->_pair, pair);
					setLeftRight();
					return node->_parent;
				}
				else
					node = node->_parent;
			}
			if (comp(pair.first, node->_pair.first))
			{
				if (!node->_left)
				{
					node->_left = _alloc_node.allocate(1);
					node->_left->_left = NULL;
					node->_left->_right = NULL;
					node->_left->_parent = node;
					_alloc.construct(&node->_left->_pair, pair);

					setLeftRight();
					return node->_left;
				}
				else
					node = insertNode(node->_left, comp, pair);
			}
			else
			{
				if (!node->_right)
				{
					node->_right = _alloc_node.allocate(1);
					node->_right->_left = NULL;
					node->_right->_right = NULL;
					node->_right->_parent = node;
					_alloc.construct(&node->_right->_pair, pair);

					setLeftRight();
					return node->_right;
				}
				else
					node = insertNode(node->_right, comp, pair);
			}
			return node;
		}

		/**
		 * @brief Obtiene el nodo padre
		 *
		 * @return tree*
		 */
		tree *getRoot() const
		{
			return _map->_parent;
		}

		/**
		 * @brief Obtiene el nodo de la izquierda
		 *
		 * @return tree*
		 */
		tree *getLeft() const
		{
			return _map->_left;
		}

		/**
		 * @brief Obtiene el nodo de la derecha
		 *
		 * @return tree*
		 */
		tree *getRight() const
		{
			return _map->_right;
		}

		typename allocator_type::template rebind<tree>::other _alloc_node;
		tree *_map;
		allocator_type _alloc;
		key_compare _comp;
		size_type _size;

	
	};

}

#endif