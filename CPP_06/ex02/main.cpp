#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    srand(time(0));
    uint type = rand() % 3;

    switch (type)
    {
        // case BASE_CLASS:
        //     return (new Base);
        case A_CLASS:
            return (new A);
        case B_CLASS:
            return (new B);
        case C_CLASS:
            return (new C);
    }
}

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
}

void identify(Base& p)
{
    (void) p;
}

int main(void)
{
    Base *seed = generate();
    identify(seed);
    identify(*seed);
    delete seed;
    return 0;
}