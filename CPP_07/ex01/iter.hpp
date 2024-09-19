#if !defined(ITER_HPP__)
#define ITER_HPP__

#include <iostream>

template <typename T, typename F>
void iter(T* addr, size_t len, F func)
{
    for (size_t i = 0; i < len; i++)
        func(addr[i]);
}

template <typename T>
void print(T type)
{
    std::cout << " | " << type;
}

template <typename T>
void increment(T& type)
{
    type++;
}

template <typename T>
void decrement(T& type)
{
    type--;
}

template <typename T>
void appand(T type)
{
    type = "_" + type + "_";
}

#endif
