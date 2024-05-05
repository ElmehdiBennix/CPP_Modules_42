
#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
       Bureaucrat e("nigga", 0);
       std::cout << e << std::endl;
    }
    catch (Bureaucrat &e)
    {
        std::cout << "execption 1 " << std::endl;
        std::cout << e << " bruhhhhh" << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "execption 2 " << std::endl;
        std::cout << e.what() << std::endl;
    }
    std::cout << "end" << std::endl;
}