#include <iostream>
#include "map.hpp"

void mapTest()
{
	std::cout << "====================" << std::endl;
	std::cout << "\tMAP" << std::endl;
	std::cout << "====================" << std::endl;

	ft::map<std::string, std::string> paises_moneda;
	std::cout << "MAIN - Inglaterra" << std::endl;
	paises_moneda["Inglaterra"] = "libra";
	std::cout << "MAIN - Espana" << std::endl;
	paises_moneda["Espana"] = "euro";
	std::cout << "MAIN - EEUU" << std::endl;
	paises_moneda["EEUU"] = "dolar";
	std::cout << "MAIN - Singapur" << std::endl;
	paises_moneda["Singapur"] = "dolar";
	std::cout << "MAIN - Egipto" << std::endl;
	paises_moneda["Egipto"] = "libra";
	std::cout << "MAIN - Marruecos" << std::endl;
	paises_moneda["Marruecos"] = "dinar";
	std::cout << "MAIN - Jordania" << std::endl;
	paises_moneda["Jordania"] = "dinar";
	std::cout << "MAIN - Jordania" << std::endl;
	paises_moneda["Jordania"] = "dinar";
	std::cout << "MAIN - Jordania" << std::endl;
	paises_moneda["Jordania"] = "dinar";
	std::cout << "MAIN - Jordania" << std::endl;
	paises_moneda["Jordania"] = "dinar";
	std::cout << "MAIN - Jordania" << std::endl;
	paises_moneda["Jordania"] = "dinar";
	std::cout << "MAIN - Jordania" << std::endl;
	paises_moneda["Jordania"] = "dinar";
	std::cout << "MAIN - Jordania" << std::endl;
	paises_moneda["Jordania"] = "dinar";
	std::cout << "MAIN - Espana" << std::endl;
	paises_moneda["Espana"] = "euro";
	std::cout << "MAIN - Australia" << std::endl;
	paises_moneda["Australia"] = "dolar";
	std::cout << "MAIN - FIN" << std::endl;
	std::cout << "La moneda usada en Egipto es: " << paises_moneda["Egipto"] << std::endl;


	paises_moneda.erase(paises_moneda.find("Marruecos"));
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
}