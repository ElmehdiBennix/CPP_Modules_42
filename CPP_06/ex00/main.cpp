#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        return (std::cerr << "Usage: ./convert <literal>" << std::endl, 1);
    return (ScalarConverter::convert(av[1]), 0);
}
