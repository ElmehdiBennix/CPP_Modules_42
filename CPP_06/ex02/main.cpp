#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
    srand(time(0));
    uint type = rand() % 3;

    switch (type)
    {
        case A_CLASS:
            return (new A);
        case B_CLASS:
            return (new B);
        case C_CLASS:
            return (new C);
    }
    return NULL;
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
    try {
        A& type = dynamic_cast<A&>(p);
        (void) type;
        std::cout << "A class type..." << std::endl;
    } catch (std::bad_cast &e) {
        try {
            B& type = dynamic_cast<B&>(p);
            (void) type;
            std::cout << "B class type..." << std::endl;
        } catch (std::bad_cast &e) {
            try {
                C& type = dynamic_cast<C&>(p);
                (void) type;
                std::cout << "C class type..." << std::endl;
            } catch (std::bad_cast &e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
}

int main(void)
{
    Base *seed = generate();

    std::cout << "===> identify pointer." << std::endl;
    identify(seed);
    std::cout << "===> identify ref." << std::endl;
    identify(*seed);
    std::cout << "===> deleting the seed." << std::endl;
    
    delete seed;
}