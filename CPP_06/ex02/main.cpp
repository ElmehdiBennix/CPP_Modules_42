#include "Seeds.hpp"

Base *generate(void)
{
    srand(time(0));
    uint type = rand() % 3;

    switch (type)
    {
        case A_CLASS:
            std::cout << "Generated Seed of type A." << std::endl;
            return (new A);
        case B_CLASS:
            std::cout << "Generated Seed of type B." << std::endl;
            return (new B);
        case C_CLASS:
            std::cout << "Generated Seed of type C." << std::endl;
            return (new C);
    }
    return NULL;
};

void identify(Base* p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A class type..." << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B class type..." << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C class type..." << std::endl;
    else
        std::cout << "unknown type..." << std::endl;
};

void identify(Base& p)
{
    try
    {
        dynamic_cast<A&>(p);
        std::cout << "A class type..." << std::endl;
    }
    catch (std::exception &b)
    {
        try
        {
            dynamic_cast<B&>(p);
            std::cout << "B class type..." << std::endl;
        }
        catch (std::exception &c)
        {
            try
            {
                dynamic_cast<C&>(p);
                std::cout << "C class type..." << std::endl;
            }
            catch (std::exception &x)
            {
                std::cout << x.what() << std::endl;
            }
        }
    }
};

int main(void)
{
    Base *seed = generate();

    std::cout << std::endl << "===> identify pointer <===" << std::endl;
    identify(seed);
    std::cout << "===> identify ref <===" << std::endl;
    identify(*seed);

    delete seed;
};
