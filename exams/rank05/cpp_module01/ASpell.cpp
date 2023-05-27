#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::ASpell(string const &name, string const &effects) : _name(name), _effects(effects) {}

ASpell::ASpell(ASpell const &other) { *this = other; }

ASpell &ASpell::operator=(ASpell const &other)
{
	_name = other._name;
	_effects = other._effects;
	return (*this);
}

ASpell::~ASpell() {}

string const &ASpell::getName() const { return _name; }

string const &ASpell::getEffects() const { return _effects; }

void ASpell::launch(ATarget const &atarget_ref) const
{
	atarget_ref.getHitBySpell((*this));
}