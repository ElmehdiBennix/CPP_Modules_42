#if !defined(EASYFIND_HPP__)
#define EASYFIND_HPP__

#include <iostream>

template<typename T>
typename T::iterator easyfind(T& container, int i)
{
    for (typename T::iterator it = container.begin(); it != container.end() ; it++)
    {
        if (*it == i)
            return it;
    }
    throw std::out_of_range("no occurance is found");
}

#endif