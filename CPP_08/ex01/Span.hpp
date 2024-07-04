#if !defined(SPAN_HPP__)
#define SPAN_HPP__

#include <iostream>

class Span
{
    private:
        int *numbers;
        

    public:
        Span(void);
        Span(unsigned int N);
        Span(Span &source);

        void    addNumber(int num);
        int     shortestSpan(void);
        int     longestSpan(void);

        ~Span(void)
        {
            std::cout << "distra is called" << std::endl;
            delete[] numbers;
        };

};

#endif