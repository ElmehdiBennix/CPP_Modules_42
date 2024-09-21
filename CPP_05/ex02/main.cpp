#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("test", 1);

        ShrubberyCreationForm la("ShrubberyCreationForm");
        RobotomyRequestForm lb("RobotomyRequestForm");
        PresidentialPardonForm lc("PresidentialPardonForm");

        std::cout << "<========================= sign =========================>" << std::endl;
        a.signForm(la);
        a.signForm(lb);
        a.signForm(lc);

        std::cout << "<========================= execute =========================>" << std::endl;
        a.executeForm(la);
        a.executeForm(lb);
        a.executeForm(lc);

    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
