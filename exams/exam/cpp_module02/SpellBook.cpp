#include "SpellBook.hpp"

SpellBook::SpellBook() {}
SpellBook::~SpellBook() {}

void SpellBook::learnSpell(ASpell *spell)
{
	if (spell)
		_arr.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
}

void SpellBook::forgetSpell(std::string const &name)
{
	_arr.erase(name);
}

ASpell *SpellBook::createSpell(std::string const &name)
{
	ASpell *spell = _arr[name];
	return spell->clone();
}
