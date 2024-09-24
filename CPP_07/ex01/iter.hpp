#if !defined(ITER_HPP__)
#define ITER_HPP__

#include <iostream>

template <typename T>
void iter(T* addr, size_t len, void (*func)(T))
{
    for (size_t i = 0; i < len; i++)
        func(addr[i]);
}

template <typename T>
void print(T type)
{
    std::cout << type << std::endl;
}

#endif
