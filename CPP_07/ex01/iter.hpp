#if !defined(ITER_HPP__)
#define ITER_HPP__

#include <iostream>

template<typename T, void (*f)() >
void iter(T* addr, size_t len, f func){

}

#endif