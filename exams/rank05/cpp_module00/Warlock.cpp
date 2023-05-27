#include "Warlock.hpp"

Warlock::Warlock(string const &name, string const &title) : _name(name), _title(title)
{
    cout << _name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() {cout << _name << ": My job here is done!\n";}

string const &Warlock::getName() const { return (_name);}
string const &Warlock::getTitle() const { return (_title);}

void Warlock::setTitle(string const &title) { _title = title;}

void Warlock::introduce() const { cout << _name << ": I am " << _name << ", " << _title << "!\n";}

