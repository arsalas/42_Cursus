#include "Character.hpp"

Character::Character(std::string name) : _name(name), _quantityMaterias(0) {}

Character::Character(const Character &other) : _name(other.getName()), _quantityMaterias(other._quantityMaterias)
{
	copyMaterias(other);
}

Character &Character::operator=(const Character &other)
{
	_name = other._name;
	_quantityMaterias = other._quantityMaterias;
	copyMaterias(other);
	return *this;
}

Character::~Character()
{
	deleteInventary();
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::deleteInventary()
{
	for (int i = 0; i < _quantityMaterias; i++)
	{
		delete _inventary[i];
	}
	_quantityMaterias = 0;
}

void Character::copyMaterias(const Character &other)
{
	deleteInventary();
	for (int i = 0; i < other._quantityMaterias; i++)
	{
		_inventary[i] = other._inventary[i]->clone();
	}
	_quantityMaterias = other._quantityMaterias;
}

bool Character::isMateriaIndexValid(int idx) const
{
	if (idx < 0 || idx >= maxMaterias)
		return false;
	return true;
}

void Character::equip(AMateria *m)
{
	if (_quantityMaterias >= maxMaterias)
		return;
	_inventary[_quantityMaterias] = m;
	_quantityMaterias++;
}

void Character::unequip(int idx)
{
	if (!isMateriaIndexValid(idx))
		return;
	delete _inventary[idx];
	_quantityMaterias--;
}

void Character::use(int idx, ICharacter &target)
{
	if (!isMateriaIndexValid(idx))
		return;
	_inventary[idx]->use(target);
}
