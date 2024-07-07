#include "Span.hpp"

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(12);

    std::vector<int>* x = sp.getvec();
    std::cout << "the size is = " << x->size() << std::endl;
    std::cout << "the capacity is = " << x->capacity() << std::endl;

    for (std::vector<int>::iterator it = x->begin(); it != x->end(); it++)
    {
        std::cout << *it << std::endl;
    }

    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;

    return 0;
}