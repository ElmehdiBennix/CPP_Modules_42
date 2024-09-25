#include <iostream>

template <typename T>
Array<T>::Array(void) : elements(NULL), len(0)
{
};

template <typename T>
Array<T>::Array(unsigned int n)
{
    this->len = n;
    (this->len == 0) ? this->elements = NULL : this->elements = new T[this->len]() ;
};

template <typename T>
Array<T>::Array(const Array &source)
{
    *this = source;
};

template <typename T>
Array<T>&
Array<T>::operator=(const Array& source)
{
    if (this != &source)
    {
        if (elements != NULL)
            delete[] elements;
        this->len = source.len;
        (this->len == 0) ? this->elements = NULL : this->elements = new T[this->len]() ;
        for (size_t i = 0 ; i < this->len; i++)
            this->elements[i] = source.elements[i];
    }
    return *this;
};

template <typename T>
T&
Array<T>::operator[](size_t index)
{
    if (index < len)
        return (this->elements[index]);
    throw (std::out_of_range("Error: accessing element out of range."));
};

template <typename T>
size_t
Array<T>::size(void) const
{
    return (this->len);
};

template <typename T>
Array<T>::~Array(void)
{
    delete[] elements;
};
