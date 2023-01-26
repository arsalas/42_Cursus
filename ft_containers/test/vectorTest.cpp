#include <iostream>
#include "vector.hpp"

void vectorTest()
{
	std::cout << "====================" << std::endl;
	std::cout << "\tVECTOR" << std::endl;
	std::cout << "====================" << std::endl;

	ft::vector<int> vect(10);
	ft::vector<std::string> vect2(10, "HOLA");

	std::cout << "Capacity: " << vect.capacity() << std::endl;
	vect.push_back(4);
	std::cout << "Capacity: " << vect.size() << std::endl;

	std::cout << "--->Start: \n";
	std::cout << "--->Iterando edades\n";
	std::cout << "Con iteradores \n";
	for (ft::vector<int>::const_iterator it = vect.begin(); it != vect.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << "\n";
	std::cout << "--->Start: \n";
	std::cout << "--->Iterando edades\n";
	std::cout << "Con iteradores reversos \n";
	for (ft::vector<int>::const_reverse_iterator it = vect.rbegin(); it != vect.rend(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << "\n";
	std::cout << "--->Iterando edades\n";
	std::cout << "Con indice usando size_t\n";
	// Iterar con índice
	for (std::size_t i = 0; i < vect2.size(); i++)
	{
		std::cout << vect2[i] << "\n";
	}

	ft::vector<int> edades;
	// Agregar elementos
	edades.push_back(21);
	edades.push_back(50);
	edades.push_back(23);
	edades.push_back(44);
	std::cout << "--->Iterando edades\n";
	std::cout << "Con indice usando size_t\n";
	// Iterar con índice
	for (std::size_t i = 0; i < edades.size(); i++)
	{
		int edad = edades[i];
		std::cout << edad << "\n";
	}

	ft::vector<std::string> nombres;
	nombres.push_back("Luis");
	nombres.push_back("John Galt");
	nombres.push_back("Hank Rearden");

	// Iterar al revés con punteros
	std::cout << "--->Iterando nombres\n";
	std::cout << "Con indice de fin a inicio\n";
	for (std::size_t i = 0; i < nombres.size(); i++)
	{
		std::string nombre = nombres[i];
		std::cout << nombre << "\n";
	}
}