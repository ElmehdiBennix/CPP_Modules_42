#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw std::invalid_argument("Error: Usage ./PmergeMe \"<numbers>\".");

        PmergeMe<std::vector< std::pair<int, int> >, std::vector<int> > vector(av);
        std::cout << "<========================================>" << std::endl;
        vector.print();
        std::cout << "<========================================>" << std::endl;
        vector.fordJohnsonAlgorithm();
        // vector.print();

        // std::vector<int> x;
        // x.erase()

        // std::pair<int , int> x;
        // x.swap();

        // std::deque<int> x;
        // x.insert()


        // PmergeMe<std::deque< std::pair<int, int>>, std::deque<int> > deque(ac, av);

    }
    catch (const std::exception &e) {
        return (CERR(e.what()), 1);
    }
    return 0;
};
