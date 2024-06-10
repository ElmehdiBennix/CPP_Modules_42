#if !defined(ITER_HPP__)
#define ITER_HPP__

#include <iostream>

template <typename T, typename F>
void iter(T* addr, size_t len, F func) {
    for (size_t i = 0; i < len; i++)
        func(addr[i])
}

template <typename T>
void print(const T& type) {
    std::cout << type << std::endl;
}

#endif