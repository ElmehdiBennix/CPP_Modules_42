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
        Array(void) {
            std::cout << "default constractor called."  << std::endl;
            this->elements = NULL;
            this->len = 0;
        };
        Array(unsigned int n) {
            std::cout << "constractor called."  << std::endl;
            this->elements = new T[n]();
            this->len = n;
        };
        Array(Array &source) {
            std::cout << "copy constractor called."  << std::endl;
            *this = source;
        };

        Array& operator=(Array& source) {
            std::cout << "operator = called." << std::endl;
            if (this != &source)
            {
                this->len = source.len;                         // from whome it comes that template  ?
                (this->len == 0) ? this->elements = NULL : this->elements = new T[this->len]() ;
                for (size_t i = 0 ; i < this->len; i++)
                    this->elements[i] = source.elements[i];
            }
            return *this;
        };
        T& operator[](size_t index) {
            // std::cout << "operator [] called." << std::endl;
            if (index < len)
                return this->elements[index];
            throw (std::out_of_range("what da sigama no mem"));
        };

        size_t size(void) const {
            // std::cout << "\'size\'membre called." << std::endl;
            return this->len;
        };

        ~Array(void) {
            std::cout << "destractor called."  << std::endl;
            delete[] elements;
        };
};

#endif