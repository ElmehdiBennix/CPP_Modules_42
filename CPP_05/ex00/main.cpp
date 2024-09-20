
#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat a("FIRST", 150);
        Bureaucrat b("SECOND", 1);
        for (int i = 0; i < 149; i++)
        {
            a.increment();
            std::cout << a << std::endl;
        }
        for (int i = 0; i < 149; i++)
        {
            b.decrement();
            std::cout << b << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cout << "===> Exception caught :" << e.what() << std::endl;
    }
    std::cout << "End..." << std::endl;
}
