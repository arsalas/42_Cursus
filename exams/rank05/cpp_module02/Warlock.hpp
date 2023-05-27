#pragma once

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

using namespace std;

class Warlock
{
    private:
        string _name;
        string _title;

        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);

        SpellBook book;
    public:
        Warlock(string const &name, string const &title);
        ~Warlock();

        string const &getName() const;
        string const &getTitle() const;

        void setTitle(string const &title);

        void introduce() const;

        void learnSpell(ASpell *aspell_ptr);
        void forgetSpell(string name);
        void launchSpell(string name, ATarget const &atarget_ref);
};