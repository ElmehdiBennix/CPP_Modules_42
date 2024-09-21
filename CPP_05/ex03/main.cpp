#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
    try
    {
        Intern someRandomIntern;
        AForm *rrf;

        std::cout << "<====================>" << std::endl;
        rrf = someRandomIntern.makeForm("presidential pardon", "first");
        if (rrf)
        {
            std::cout << *rrf << std::endl;
            delete rrf;
        }

        std::cout << "<====================>" << std::endl;
        rrf = someRandomIntern.makeForm("robotomy request", "second");
        if (rrf)
        {
            std::cout << *rrf << std::endl;
            delete rrf;
        }

        std::cout << "<====================>" << std::endl;
        rrf = someRandomIntern.makeForm("shrubbery creation", "third");
        if (rrf)
        {
            std::cout << *rrf << std::endl;
            delete rrf;
        }

        std::cout << "<====================>" << std::endl;
        rrf = someRandomIntern.makeForm("non existant", "third");
        if (rrf)
        {
            std::cout << *rrf << std::endl;
            delete rrf;
        }

    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
