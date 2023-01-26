#ifndef PAIR_H
#define PAIR_H

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		// ==============================================================
		// 							MEMBER TYPES
		// ==============================================================

		typedef T1 first_type;
		typedef T2 second_type;

		pair() : first(), second() {}

		pair(const first_type &a, const second_type &b) : first(a), second(b) {}

		template <class U, class V>
		pair(const pair<U, V> &pr) : first(pr.first), second(pr.second) {}

		~pair() {}

		pair<T1, T2> &operator=(const pair<T1, T2> &pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}

		first_type first;
		second_type second;
	};

	// ==============================================================
	// 							OPERATORS
	// ==============================================================

	template <class T1, class T2>
	bool operator==(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return lhs.first == rhs.first && lhs.second == rhs.second;
	};

	template <class T1, class T2>
	bool operator!=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return !(lhs == rhs);
	};

	template <class T1, class T2>
	bool operator<(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
	};

	template <class T1, class T2>
	bool operator<=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return !(rhs < lhs);
	};

	template <class T1, class T2>
	bool operator>(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return rhs < lhs;
	};

	template <class T1, class T2>
	bool operator>=(const ft::pair<T1, T2> &lhs, const ft::pair<T1, T2> &rhs)
	{
		return !(lhs < rhs);
	};

	template <class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return ft::pair<T1, T2>(t, u);
	};
}

#endif