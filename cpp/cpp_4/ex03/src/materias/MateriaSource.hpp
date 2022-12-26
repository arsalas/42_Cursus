#ifndef MATERIA_SOURCE_H
#define MATERIA_SOURCE_H

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{

private:
	static const int maxMaterias = 4;
	AMateria *_inventary[maxMaterias];
	int _quantityMaterias;

public:
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource &operator=(const MateriaSource &other);
	~MateriaSource();

	void learnMateria(AMateria *);
	AMateria *createMateria(std::string const &type);

private:
	void deleteInventary();
	void copyMaterias(const MateriaSource &other);
};

#endif