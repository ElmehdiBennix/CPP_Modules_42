#ifndef INTERN_HPP__
#define INTERN_HPP__

#include <iostream>

class AForm;

class Intern
{
    public:
        Intern(void);
        Intern(const Intern& source);

        Intern& operator=(const Intern& source);

        AForm *makeForm(const std::string& name, const std::string& target);

        ~Intern(void);
};

#endif
