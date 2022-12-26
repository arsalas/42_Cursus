#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : _type(type)
{
}

AMateria::AMateria(const AMateria &other) : _type(other._type)
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
	_type = other._type;
	return *this;
}

AMateria::~AMateria()
{
}

const std::string &AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << _type << " used against " << target.getName() << std::endl;
}