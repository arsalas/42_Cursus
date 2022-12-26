#ifndef ICE_H
#define ICE_H

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice();
	Ice(const Ice &other);
	Ice &operator=(const Ice &other);
	~Ice();

	Ice* clone() const;
	void use(ICharacter& target);
};

#endif