#if !defined(RPN_HPP__)
#define RPN_HPP__

#include <iostream>
#include <stack>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

#define COUT(out) std::cout << GREEN << out << RESET << std::endl
#define CWAR(out) std::cout << YELLOW << out << RESET << std::endl
#define CERR(out) std::cerr << RED << out << RESET << std::endl

class RPN
{
    private:
        

    public:
        RPN(void);
        RPN(const std::string& expression);
        RPN(const RPN& source);

        RPN& operator=(const RPN& source);

        // void

        ~RPN();
};

#endif
