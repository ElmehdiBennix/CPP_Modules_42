#if !defined(ARRAY_HPP__)
#define ARRAY_HPP__

#include <iostream>

template <typename T>
class Array
{
    private:
        T       *elements;
        size_t  len;

    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array &source);

        Array&  operator=(const Array& source);
        T&      operator[](size_t index);

        size_t  size(void) const;

        ~Array(void);
};

#include "Array.tpp"

#endif
