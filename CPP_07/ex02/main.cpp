#include "Array.hpp"

#if 0
int main(void) {
    // Allocating memory without initialization
    int* p1 = new int;
    std::cout << "Value after new int: " << *p1 << std::endl;

    // Allocating memory with zero initialization
    int* p2 = new int();
    std::cout << "Value after new int(): " << *p2 << std::endl;

    // Clean up
    delete p1;
    delete p2;

    return 0;
}
#endif

#if 1
int main(void)
{
    Array<int> table(6);
    // Array<std::string> strTable(table);

    // char c[6] = {'s','t','r','i','n','g'};
    int x[6] = {1,2,3,4,5,6};
    std::string str[6] = {"s","t","r","i","n","g"};

    try {
        std::cout << "Array size = " << table.size() << std::endl;

        for (size_t i = 0; i < table.size() ; i++)
            std::cout << " | " << table[i];
        std::cout << " |" << std::endl;

        for (size_t i = 0; i < table.size() ; i++)
            table[i] = x[i];

        for (size_t i = 0; i < table.size() ; i++)
            std::cout << " | " << table[i];
        std::cout << " |" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

#endif
