#include "ATarget.hpp"

class ASpell;

ATarget::ATarget(std::string const type) : _type(type) {}

ATarget::~ATarget() {}

const std::string &ATarget::getType() const
{
	return _type;
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!\n";
}
