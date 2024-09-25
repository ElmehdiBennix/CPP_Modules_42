#include "iter.hpp"
#define SIZE 5

int main(void)
{
    size_t      size = 0;

    std::cout << "<======>" << std::endl;

    char c[SIZE] = {'h', 'e', 'l','l','o'};
    size = sizeof(c) / sizeof(c[0]);

    iter(c , size, print<char>);
    std::cout << "<======>" << std::endl;

    int num[SIZE] = {1,2,3,4,5};
    size = sizeof(num) / sizeof(num[0]);

    iter(num , size, print<int>);
    std::cout << "<======>" << std::endl;

    double doub[SIZE] = {1.2, 3.4, 4.5, 6.7, 8.9};
    size = sizeof(doub) / sizeof(doub[0]);

    iter(doub , size, print<double>);
    std::cout << "<======>" << std::endl;

    std::string str[SIZE] = {"hello", "this", "is", "an", "array"};
    size = sizeof(str) / sizeof(str[0]);

    iter(str , size, print<std::string>);
    std::cout << "<======>" << std::endl;

    return 0;
}
