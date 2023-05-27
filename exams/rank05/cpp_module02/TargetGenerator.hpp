#pragma once

#include "ATarget.hpp"
#include <map>

using namespace std;

class TargetGenerator
{
    private:
        map<string, ATarget *> _arr_target;

        TargetGenerator(TargetGenerator const &other);
        TargetGenerator &operator=(TargetGenerator const &other);

    public:
        TargetGenerator();
        ~TargetGenerator();

        void learnTargetType(ATarget *target_ptr);
        void forgetTargetType(string const &name);
        ATarget* createTarget(string const &name);
};