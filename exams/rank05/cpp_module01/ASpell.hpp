#pragma once

#include <iostream>

using namespace std;

class ATarget;

class ASpell
{
    private:
        string _name;
        string _effects;

    public:
        ASpell();
        ASpell(string const &name, string const &effects);
        ASpell(ASpell const &other);
        ASpell &operator=(ASpell const &other);
        virtual ~ASpell();

        string const &getName() const;
        string const &getEffects() const;

        void launch(ATarget const &atarget_ref) const;

        virtual ASpell *clone() const = 0;
};

#include "ATarget.hpp"