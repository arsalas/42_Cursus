#pragma once

#include "ASpell.hpp"

using namespace std;

class Fwoosh: public ASpell
{
    public:
        Fwoosh();
        ~Fwoosh();

        virtual ASpell *clone() const;
};