#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget() {}

ATarget::ATarget(string const &type) : _type(type) {}

ATarget::ATarget(ATarget const &other) { *this = other; }

ATarget &ATarget::operator=(ATarget const &other)
{
	_type = other._type;
	return (*this);
}

ATarget::~ATarget() {}

string const &ATarget::getType() const { return _type; }

void ATarget::getHitBySpell(ASpell const &aspell_ref) const
{
	cout << _type << " has been " << aspell_ref.getEffects() << "!\n";
}
