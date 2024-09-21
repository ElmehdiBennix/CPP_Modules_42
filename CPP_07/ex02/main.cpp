#include "Array.hpp"
#define SIZE 6

int main(void)
{
    try
    {
        Array<int>         table(SIZE);
        // Array<char>        table(SIZE);
        // Array<std::string> table(SIZE);

        int         x[SIZE] = {1,2,3,4,5,6};
        // char        x[SIZE] = {'s','t','r','i','n','g'};
        // std::string x[SIZE] = {"hello","this","is","a","test","."};


        std::cout << "Array size = " << table.size() << std::endl;
        std::cout << "<===========================>" << std::endl;

        for (size_t i = 0; i < table.size() ; i++)
            std::cout << " | " << table[i];
        std::cout << " |" << std::endl;

        for (size_t i = 0; i < table.size() ; i++)
            table[i] = x[i];

        for (size_t i = 0; i < table.size() ; i++)
            std::cout << " | " << table[i];
        std::cout << " |" << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
};
