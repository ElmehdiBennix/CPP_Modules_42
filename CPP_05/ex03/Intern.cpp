#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "Default constractor called for the Intern" << std::endl;

};
// Intern(const Intern& source);

AForm* Intern::makeForm(const std::string& name, const std::string& target) {
    int i;
    std::string type[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};

    for (i = 0 ; i < 3 && type[i] != name ; i++);

    if (type[i] == name)
    {
        switch (i)
        {
            case 0:
                std::cout << "Inetern creates " << name << std::endl;
                return new PresidentialPardonForm(target);
            case 1:
                std::cout << "Inetern creates " << name << std::endl;
                return new RobotomyRequestForm(target);
            case 2:
                std::cout << "Inetern creates " << name << std::endl;
                return new ShrubberyCreationForm(target);
        }
    }
    std::cout << "Inetern couldn't find " << name << std::endl;
    return NULL;
};

Intern::~Intern(void)
{
    std::cout << "Distractor called for the Intern" << std::endl;
};
