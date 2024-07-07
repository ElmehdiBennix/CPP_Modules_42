#if !defined(SPAN_HPP__)
#define SPAN_HPP__

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private:
        std::vector<int> numbers;
        std::size_t size;

    public:
        Span(void) {
            numbers.reserve(1);
            size = 1;
        };
        Span(unsigned int N) {
            numbers.reserve(N);
            size = N;
        };
        Span(const Span &source) {
            *this = source;
        };

        Span& operator=(const Span &source) {
            if (this != &source) {
                numbers.resize(source.size);
                std::copy(source.numbers.begin(), source.numbers.end(), this->numbers.begin());
                size = source.size;
            }
            return (*this);
        };

        void    addNumber(int num) {
            if (size > numbers.size())
                std::cout << "passed" << std::endl;
            numbers.push_back(num);
        };

        std::vector<int>* getvec(void){return &numbers;};

        // int     shortestSpan(void) {

        // };

        // int     longestSpan(void) {

        // };

        ~Span(void) {};
};

#endif