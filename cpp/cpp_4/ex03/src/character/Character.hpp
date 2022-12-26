#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
	std::string _name;
	static const int maxMaterias = 4;
	AMateria *_inventary[maxMaterias];
	int _quantityMaterias;

public:
	Character(std::string name);
	Character(const Character &other);
	Character &operator=(Character &other);
	~Character();

	std::string const &getName() const;
	void equip(AMateria *m);
	void unequip(int idx);
	void use(int idx, ICharacter &target);

private:
	Character();
	void deleteInventary();
	bool isMateriaIndexValid(int idx) const;
	void copyMaterias(const Character &other);
};

#endif