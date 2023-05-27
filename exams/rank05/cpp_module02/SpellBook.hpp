#pragma once

#include "ASpell.hpp"
#include <map>

using namespace std;

class SpellBook
{
    private:
        map<string, ASpell *> _arr_spell;

        SpellBook(SpellBook const &other);
        SpellBook &operator=(SpellBook const &other);

    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell *aspell_ptr);
        void forgetSpell(string const &name);
        ASpell* createSpell(string const &name);

};