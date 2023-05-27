#include "Warlock.hpp"

Warlock::Warlock(string const &name, string const &title) : _name(name), _title(title)
{
	cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	cout << _name << ": My job here is done!\n";
}

string const &Warlock::getName() const { return _name; }
string const &Warlock::getTitle() const { return _title; }

void Warlock::setTitle(string const &title) { _title = title; }

void Warlock::introduce() const { cout << _name << ": I am " << _name << ", " << _title << "!\n"; }

void Warlock::learnSpell(ASpell *spell_ptr)
{
	if (spell_ptr)
		_arr.insert(pair<string, ASpell *>(spell_ptr->getName(), spell_ptr->clone()));
}

void Warlock::forgetSpell(string spell_name)
{
	map<string, ASpell *>::iterator it = _arr.find(spell_name);
	if (it != _arr.end())
		delete it->second;
	_arr.erase(spell_name);
}

void Warlock::launchSpell(string spell_name, ATarget const &target_ref)
{
	try
	{
		ASpell *spell = _arr.at(spell_name);
		if (spell)
			spell->launch(target_ref);
	}
	catch (const std::exception &e)
	{
	}
}
