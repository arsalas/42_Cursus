#pragma once

#include <iostream>

using namespace std;

class Warlock
{
    private:
        string _name;
        string _title;

        Warlock();
        Warlock(Warlock const &other);
        Warlock &operator=(Warlock const &other);
    public:
        Warlock(string const &name, string const &title);
        ~Warlock();

        string const &getName() const;
        string const &getTitle() const;

        void setTitle(string const &title);

        void introduce() const;
};