#ifndef SPELLBOOK_H
#define SPELLBOOK_H
#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
private:
	std::map<std::string, ASpell *> _arr;

	SpellBook(SpellBook const &other);
	SpellBook &operator=(SpellBook const &other);

public:
	SpellBook();
	~SpellBook();

	void learnSpell(ASpell *);
	void forgetSpell(std::string const &);
	ASpell *createSpell(std::string const &);
};

#endif