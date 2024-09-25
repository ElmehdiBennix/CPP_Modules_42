#include "easyfind.hpp"

int main(void)
{
    std::vector<int> numbers;

    numbers.push_back(0);
    numbers.push_back(1);
    numbers.push_back(2);
    numbers.push_back(3);
    numbers.push_back(4);
    numbers.push_back(5);

    try
    {
        std::cout << "number => " << *easyfind(numbers, 2) << std::endl;
        std::cout << "number => " << *easyfind(numbers, 0) << std::endl;
        std::cout << "number => " << *easyfind(numbers, 1) << std::endl;
        std::cout << "number => " << *easyfind(numbers, 5) << std::endl;
        std::cout << "number => " << *easyfind(numbers, 10) << std::endl;

    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
};
