#ifndef CURE_H
#define CURE_H

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure();
	Cure(const Cure &other);
	Cure &operator=(const Cure &other);
	~Cure();

	Cure* clone() const;
	void use(ICharacter& target);
};

#endif