#include "MateriaSource.hpp"
#include "AMateria.hpp"

void MateriaSource::deleteInventary()
{
	for (int i = 0; i < _quantityMaterias; i++)
	{
		delete _inventary[i];
	}
	_quantityMaterias = 0;
}

void MateriaSource::copyMaterias(const MateriaSource &other)
{
	deleteInventary();
	for (int i = 0; i < other._quantityMaterias; i++)
	{
		_inventary[i] = other._inventary[i]->clone();
	}
	_quantityMaterias = other._quantityMaterias;
}

MateriaSource::MateriaSource() : _quantityMaterias(0) {}

MateriaSource::~MateriaSource()
{
	deleteInventary();
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	copyMaterias(other);
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	deleteInventary();
	copyMaterias(other);
	return *this;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	if (_quantityMaterias >= maxMaterias)
		return;
	_inventary[_quantityMaterias] = materia;
	_quantityMaterias++;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < _quantityMaterias; i++)
	{
		if (_inventary[i]->getType() == type)
			return _inventary[i]->clone();
	}
	return NULL;
}
