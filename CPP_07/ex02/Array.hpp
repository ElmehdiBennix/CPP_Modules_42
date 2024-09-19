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
        Array(void) : elements(NULL), len(0)
        {
        };

        Array(unsigned int n) {
            this->elements = new T[n]();
            this->len = n;
        };

        Array(Array &source)
        {
            *this = source;
        };

        Array& operator=(Array& source)
        {
            if (this != &source)
            {
                this->len = source.len;                         // from whome it comes that template  ?
                (this->len == 0) ? this->elements = NULL : this->elements = new T[this->len]() ;
                for (size_t i = 0 ; i < this->len; i++)
                    this->elements[i] = source.elements[i];
            }
            return *this;
        };

        T& operator[](size_t index)
        {
            // std::cout << "operator [] called." << std::endl;
            if (index < len)
                return this->elements[index];
            throw (std::out_of_range("what da sigma"));
        };

        size_t size(void) const
        {
            // std::cout << "\'size\'membre called." << std::endl;
            return this->len;
        };

        ~Array(void)
        {
            delete[] elements;
        };
};

#endif
