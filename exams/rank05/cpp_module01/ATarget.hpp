#pragma once

#include <iostream>

using namespace std;

class ASpell;

class ATarget
{
    private:
        string _type;
    
    public:
        ATarget();
        ATarget(string const &type);
        ATarget(ATarget const &other);
        ATarget &operator=(ATarget const &other);
        virtual ~ATarget();

        string const &getType() const;

        void getHitBySpell(ASpell const &aspell_ref) const;

        virtual ATarget *clone() const = 0;
};

#include "ASpell.hpp"