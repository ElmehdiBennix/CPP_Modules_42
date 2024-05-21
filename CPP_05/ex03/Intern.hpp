#ifndef INTERN_HPP__
#define INTERN_HPP__

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
    public:
        Intern(void);

        AForm *makeForm(const std::string& name, const std::string& target);

        ~Intern(void);
};

#endif