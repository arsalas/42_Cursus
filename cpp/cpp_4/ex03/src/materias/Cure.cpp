

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
}

Cure::Cure(const Cure &other) : AMateria(other._type)
{
}

Cure &Cure::operator=(const Cure &other)
{
	_type = other._type;
	return *this;
}

Cure::~Cure()
{
}

Cure *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}