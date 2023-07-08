#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!\n";
}

void Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!\n";
}

std::string const &Warlock::getName() const
{
	return _name;
}

std::string const &Warlock::getTitle() const
{
	return _title;
}

void Warlock::setTitle(std::string const &title)
{
	_title = title;
}

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
		_spells.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}
void Warlock::forgetSpell(std::string spell)
{
	_spells.erase(spell);
}
void Warlock::launchSpell(std::string name, ATarget const &target)
{
	ASpell *spell = _spells[name];
	if (spell)
		spell->launch(target);
}
