#include "Form.hpp"
#include "Bureaucrat.hpp"

int main(void )
{
    try
    {
        Bureaucrat a("A", 30);

        Form la("Level 1", 1, 150);
        Form lb("Level 2", 50, 150);
        Form lc("Level 3", 100, 150);

        a.signForm(la);
        a.signForm(lb);
        a.signForm(lc);
    }
    catch (const std::exception &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    return 0;
}
