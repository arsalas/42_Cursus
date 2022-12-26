#ifndef AMateria_H
#define AMateria_H

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type;

public:
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	AMateria &operator=(const AMateria &other);
	virtual ~AMateria();
	std::string const &getType() const; // Returns the materia type

	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

#endif