#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::~SpellBook()
{
}

void SpellBook::learnSpell(ASpell *spell_ptr)
{
	if (spell_ptr)
		_arr_spell.insert(pair<string, ASpell *>(spell_ptr->getName(), spell_ptr->clone()));
}

void SpellBook::forgetSpell(string const &spell_name)
{
	map<string, ASpell *>::iterator it = _arr_spell.find(spell_name);
	if (it != _arr_spell.end())
		delete it->second;
	_arr_spell.erase(spell_name);
}

ASpell *SpellBook::createSpell(string const &spell_name)
{
	map<string, ASpell *>::iterator it = _arr_spell.find(spell_name);
	if (it != _arr_spell.end())
		try
		{
			return _arr_spell.at(spell_name);
		}
		catch (const std::exception &e)
		{
		}
	return NULL;
}
