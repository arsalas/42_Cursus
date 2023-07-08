#include "ASpell.hpp"

class ATarget;

ASpell::ASpell(std::string const name, std::string const effects) : _name(name), _effects(effects)
{
}

ASpell::~ASpell() {}

const std::string &ASpell::getName() const
{
	return _name;
}

const std::string &ASpell::getEffects() const
{
	return _effects;
}

void ASpell::launch(ATarget const &target) const
{
	target.getHitBySpell((*this));
}
