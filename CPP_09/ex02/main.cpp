#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac == 1)
            throw std::invalid_argument("Error: Usage ./PmergeMe \"<sequence>\".");


        return 0;
    }
    catch (const std::exception &e) {
        return (CERR(e.what()), 1);
    }
};
