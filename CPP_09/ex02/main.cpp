#include "PmergeMe.hpp"

static  int getToken(char *arg)
{
    int                 number;
    std::stringstream   oss(arg);

    for (size_t i = 0; arg[i]; i++)
    {
        if (!std::isdigit(arg[i]))
            throw std::invalid_argument("Error: invalid token.");
    }

    if (!(oss >> number))
        throw std::invalid_argument("Error: invalid conversion to int.");

    return (number);
};

static void  executionLog(size_t size, const std::string& type , double time)
{
    std::cout << std::fixed << "Time to process a range of "
              << size << " elements with " << type << " : " << time << " us" << std::endl;
}

int main(int ac, char **av)
{
    try
    {
        if (ac < 2)
            throw std::invalid_argument("Error: Usage ./PmergeMe \"<numbers>\".");

        std::vector<int>  numbers;

        for (size_t i = 1; av[i]; i++)
            numbers.push_back(getToken(av[i]));

        for (size_t i = 0; i < numbers.size(); i++)
        {
            for (size_t j = i + 1; j < numbers.size(); j++)
            {
                if (numbers[i] == numbers[j])
                    throw std::invalid_argument("Error: invalid duplicates numbers.");
            }
        }

        double ExecTime[2];

        COUT("BEFORE : " << RESET << numbers);

        PmergeMeVector sortV(numbers);
        PmergeMeDeque sortD(numbers);

        sortV.fordJohnsonAlgorithm();
        ExecTime[0] = (double)(clock() - sortV.getStart()) / CLOCKS_PER_SEC;

        sortD.fordJohnsonAlgorithm();
        ExecTime[1] = (double)(clock() - sortD.getStart()) / CLOCKS_PER_SEC;

        COUT("AFTER  : " << RESET << sortV.getMainChain());
        executionLog(numbers.size(), "std::vector<int>", ExecTime[0]);
        executionLog(numbers.size(), "std::deque<int> ", ExecTime[1]);
        sortV.isSorted();
        sortD.isSorted();

        // std::cout << "======================================" << std::endl;

        // CWAR(calculateJacobSthal(20));
    }
    catch (const std::exception &e) {
        return (CERR(e.what()), 1);
    }
    return 0;
};
