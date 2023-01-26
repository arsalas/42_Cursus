#include <iostream>
#include "map.hpp"

void mapTest()
{
	std::cout << "====================" << std::endl;
	std::cout << "\tMAP" << std::endl;
	std::cout << "====================" << std::endl;

	ft::map<std::string, std::string> paises_moneda;
	paises_moneda["Espana"] = "euro";
	paises_moneda["EEUU"] = "dolar";
	paises_moneda["Singapur"] = "dolar";
	paises_moneda["Inglaterra"] = "libra";
	paises_moneda["Egipto"] = "libra";
	paises_moneda["Marruecos"] = "dinar";
	paises_moneda["Jordania"] = "dinar";
	paises_moneda["Jordania"] = "dinar";
	std::cout << "La moneda usada en Egipto es: " << paises_moneda["Egipto"] << std::endl;

	ft::map<std::string, std::string>::iterator it;
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
}