#include <iostream>
#include <map>
#include "map.hpp"

void mapTest()
{
	std::cout << "====================" << std::endl;
	std::cout << "\tMAP" << std::endl;
	std::cout << "====================" << std::endl;

	ft::map<std::string, std::string> paises_moneda;
	ft::map<std::string, std::string>::iterator it;
	paises_moneda["Inglaterra"] = "libra";
	paises_moneda["Espana"] = "euro";
	paises_moneda["EEUU"] = "dolar";
	paises_moneda["Singapur"] = "dolar";
	paises_moneda["Egipto"] = "libra";
	paises_moneda["Marruecos"] = "dinar";
	paises_moneda["Jordania"] = "dinar";
	paises_moneda["Jordania"] = "dinar";
	paises_moneda["Jordania"] = "dinar";
	paises_moneda["Jordania"] = "dinar";
	paises_moneda["Jordania"] = "dinar";
	paises_moneda["Jordania"] = "dinar";
	paises_moneda["Jordania"] = "dinar";
	paises_moneda["Espana"] = "euro";
	paises_moneda["Australia"] = "dolar";
	std::cout << "La moneda usada en Egipto es: " << paises_moneda["Egipto"] << std::endl;

	paises_moneda.erase(paises_moneda.find("Marruecos"));
	// paises_moneda.clear();
	std::cout << "Iteracion paises: " << std::endl;
	for (it = paises_moneda.begin(); it != paises_moneda.end(); it++)
	{
		std::cout << it->first // string (key)
				  << "->"
				  << it->second // string's value
				  << std::endl;
	}
	std::cout << "Size: " << paises_moneda.size() << std::endl;
	std::cout << paises_moneda.count("Jordania") << std::endl;
	ft::map<std::string, std::string> paises_moneda_copy = paises_moneda;
	std::cout << "Iteracion paises copia: " << std::endl;
	for (it = paises_moneda_copy.begin(); it != paises_moneda_copy.end(); it++)
	{
		std::cout << it->first // string (key)
				  << "->"
				  << it->second // string's value
				  << std::endl;
	}
	std::cout << "Size: " << paises_moneda_copy.size() << std::endl;
	std::cout << paises_moneda_copy.count("Jordania") << std::endl;

	ft::map<int, char> map;
	map[2] = 'a';
	map[67] = 'u';
	ft::map<int, char>::iterator it2;

	std::cout << "Iteracion map2: " << std::endl;
	for (it2 = map.begin(); it2 != map.end(); it2++)
	{
		std::cout << it2->first // string (key)
				  << "->"
				  << it2->second // string's value
				  << std::endl;
	}

	{
		ft::map<char, int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		// show content:
		for (ft::map<char, int>::iterator it = mymap.begin(); it != mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';
	}

	{
		ft::map<char, int> mymap;

		mymap['x'] = 1001;
		mymap['y'] = 2002;
		mymap['z'] = 3003;

		std::cout << "mymap contains:\n";

		ft::pair<char, int> highest = *(mymap.rbegin()); // last element
		std::cout << "PAIR: " << highest.first << std::endl;
		ft::map<char, int>::iterator it = mymap.begin();
		do
		{
			std::cout << it->first << " => " << it->second << '\n';
		} while (mymap.value_comp()(*it++, highest));
	}
}