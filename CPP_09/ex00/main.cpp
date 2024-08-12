#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (CWAR("Error: Usage ./btc <filepath>."), 1);

    try {
        Bitcoin data;
        data.exchange(av[1]);
    }
    catch (std::exception &e) {
        CERR(e.what());
        return 2;
    }

    return 0;
}
