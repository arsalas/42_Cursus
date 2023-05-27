#pragma once

#include "ATarget.hpp"

using namespace std;

class Dummy: public ATarget
{
    public:
        Dummy();
        ~Dummy();

        virtual ATarget *clone() const;
};