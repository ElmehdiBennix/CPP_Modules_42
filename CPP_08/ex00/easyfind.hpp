#if !defined(EASYFIND_HPP__)
#define EASYFIND_HPP__

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int target)
{
    typename T::iterator it = std::find(container.begin(), container.end(), target);
    if (it == container.end())
        throw std::out_of_range("no occurance found.");
    return (it);
};

#endif
