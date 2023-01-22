#ifndef UTILS_H
#define UTILS_H

namespace ft
{

	template <bool flag, class const_type, class normal_type>
	struct choose_type;

	template <class const_type, class normal_type>
	struct choose_type<true, const_type, normal_type>
	{
		typedef const_type type;
	};

	template <class const_type, class normal_type>
	struct choose_type<false, const_type, normal_type>
	{
		typedef normal_type type;
	};

	template <class T>

	struct less
	{
		typedef bool result_type;
		typedef T first_argument_type;
		typedef T second_argument_type;

		bool operator()(const T &lhs, const T &rhs) const
		{
			return lhs < rhs;
		}
	};

	template <class Compare, class T>
	class Comp
	{
	public:
		Comp(Compare c) : comp_(c){};

		bool operator()(const T &x, const T &y) const { return comp_(x.first, y.first); };

		Compare comp_;
	};

}
#endif