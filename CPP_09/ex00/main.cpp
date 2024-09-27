#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw std::invalid_argument("Error: Usage ./btc <filepath>.");

        Bitcoin data;
        data.exchange(av[1]);
    }
    catch (std::exception &e) {
        return (CERR(e.what()), 1);
    }
    return 0;
}
