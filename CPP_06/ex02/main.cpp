#include "Seeds.hpp"

int main(void)
{
    Base *seed = generate();

    std::cout << std::endl << "===> identify pointer <===" << std::endl;
    identify(seed);
    std::cout << "===> identify ref <===" << std::endl;
    identify(*seed);

    delete seed;
};
