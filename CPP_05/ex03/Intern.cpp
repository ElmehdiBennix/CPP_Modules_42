#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
};

Intern::Intern(const Intern& source)
{
    (void)source;
};

Intern&
Intern::operator=(const Intern& source)
{
    (void)source;
    return (*this);
};

AForm*
Intern::makeForm(const std::string& name, const std::string& target)
{
    int i = 0;
    std::string type[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

    for (i = 0 ; i < 3 && type[i] != name ; i++);

    if (type[i] == name)
    {
        switch (i)
        {
            case 0:
                std::cout << "Intern creates " << name << std::endl;
                return new PresidentialPardonForm(target);
            case 1:
                std::cout << "Intern creates " << name << std::endl;
                return new RobotomyRequestForm(target);
            case 2:
                std::cout << "Intern creates " << name << std::endl;
                return new ShrubberyCreationForm(target);
        }
    }
    std::cout << "Intern couldn't find " << name << std::endl;
    return NULL;
};

Intern::~Intern(void)
{
};
