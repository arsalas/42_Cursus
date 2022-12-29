#include <iostream>
#include "whatever.hpp"

int main(void)
{
	{
		std::cout << "==============================" << std::endl;
		std::cout << "\tSAWAP INT" << std::endl;
		std::cout << "==============================" << std::endl;
		int n1 = 42;
		int n2 = 24;
		std::cout << "n1 = " << n1 << ", n2 = " << n2 << std::endl;
		::swap(n1, n2);
		std::cout << "n1 = " << n1 << ", n2 = " << n2 << std::endl;
		std::cout << std::endl;
		std::cout << "==============================" << std::endl;
		std::cout << "\tSAWAP FLOAT" << std::endl;
		std::cout << "==============================" << std::endl;
		float f1 = 42.10f;
		float f2 = 24.5f;
		std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
		::swap(f1, f2);
		std::cout << "f1 = " << f1 << ", f2 = " << f2 << std::endl;
		std::cout << std::endl;
		std::cout << "==============================" << std::endl;
		std::cout << "\tSAWAP STRING" << std::endl;
		std::cout << "==============================" << std::endl;
		std::string s1 = "aa";
		std::string s2 = "bb";
		std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
		::swap(s1, s2);
		std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "==============================" << std::endl;
		std::cout << "\tMAX INT" << std::endl;
		std::cout << "==============================" << std::endl;
		int n1 = 42;
		int n2 = 24;
		std::cout << "n1 = " << n1 << ", n2 = " << n2 << std::endl;
		std::cout << "max: " << ::max(n1, n2) << std::endl;
		n1 = 42;
		n2 = 42;
		std::cout << "n1 = " << n1 << ", n2 = " << n2 << std::endl;
		std::cout << "max: " << ::max(n1, n2) << std::endl;
		std::cout << std::endl;
		std::cout << "==============================" << std::endl;
		std::cout << "\tMAX FLOAT" << std::endl;
		std::cout << "==============================" << std::endl;
		float f1 = 42.5f;
		float f2 = 24.42f;
		std::cout << "n1 = " << f1 << ", n2 = " << f2 << std::endl;
		std::cout << "max: " << ::max(f1, f2) << std::endl;
		f1 = 42.42f;
		f2 = 42.42f;
		std::cout << "n1 = " << f1 << ", n2 = " << f2 << std::endl;
		std::cout << "max: " << ::max(f1, f2) << std::endl;
		std::cout << std::endl;
		std::cout << "==============================" << std::endl;
		std::cout << "\tMAX STRING" << std::endl;
		std::cout << "==============================" << std::endl;
		std::string s1 = "aa";
		std::string s2 = "bb";
		std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
		std::cout << "max: " << ::max(s1, s2) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "==============================" << std::endl;
		std::cout << "\tMIN INT" << std::endl;
		std::cout << "==============================" << std::endl;
		int n1 = 42;
		int n2 = 24;
		std::cout << "n1 = " << n1 << ", n2 = " << n2 << std::endl;
		std::cout << "min: " << ::min(n1, n2) << std::endl;
		n1 = 42;
		n2 = 42;
		std::cout << "n1 = " << n1 << ", n2 = " << n2 << std::endl;
		std::cout << "min: " << ::min(n1, n2) << std::endl;
		std::cout << std::endl;
		std::cout << "==============================" << std::endl;
		std::cout << "\tMIN FLOAT" << std::endl;
		std::cout << "==============================" << std::endl;
		float f1 = 42.10f;
		float f2 = 24.5f;
		std::cout << "n1 = " << f1 << ", n2 = " << f2 << std::endl;
		std::cout << "min: " << ::min(f1, f2) << std::endl;
		f1 = 42.42f;
		f2 = 42.42f;
		std::cout << "n1 = " << f1 << ", n2 = " << f2 << std::endl;
		std::cout << "min: " << ::min(f1, f2) << std::endl;
		std::cout << std::endl;
		std::cout << "==============================" << std::endl;
		std::cout << "\tMIN STRING" << std::endl;
		std::cout << "==============================" << std::endl;
		std::string s1 = "aa";
		std::string s2 = "bb";
		std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
		std::cout << "min: " << ::min(s1, s2) << std::endl;
		std::cout << std::endl;
	}
	{
		std::cout << "==============================" << std::endl;
		std::cout << "\tSUBJECT MAIN" << std::endl;
		std::cout << "==============================" << std::endl;

		int a = 2;
		int b = 3;
		::swap(a, b);
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min(a, b) << std::endl;
		std::cout << "max( a, b ) = " << ::max(a, b) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min(c, d) << std::endl;
		std::cout << "max( c, d ) = " << ::max(c, d) << std::endl;
	}
	return 0;
}