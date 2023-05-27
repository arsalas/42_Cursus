#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title) : _name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!\n";
}

std::string const &Warlock::getName() const { return _name; }
std::string const &Warlock::getTitle() const { return _title; }

void Warlock::setTitle(std::string const &title) { _title = title; }

void Warlock::introduce() const { std::cout << _name << ": I am " << _name << ", " << _title << "!\n"; }

void Warlock::learnSpell(ASpell *aspell_ptr)
{
	book.learnSpell(aspell_ptr);
}

void Warlock::forgetSpell(std::string name)
{
	book.forgetSpell(name);
}

void Warlock::launchSpell(std::string name, ATarget const &atarget_ref)
{
	ASpell *temp = book.createSpell(name);
	if (temp)
		temp->launch(atarget_ref);
}
