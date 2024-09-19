#include "RPN.hpp"

int main(int ac, char **av)
{
    try {
        if (ac != 2)
            throw std::invalid_argument("Error: Usage ./RPN \"<inverted Polish mathematical expression>\".");

        RPN;
    }
    catch (std::exception &e) {
        return (CERR(e.what()), 1);
    }

    return 0;
}
