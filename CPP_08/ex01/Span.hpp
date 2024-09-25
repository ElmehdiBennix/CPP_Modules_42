#if !defined(SPAN_HPP__)
#define SPAN_HPP__

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private:
        std::vector<int>    numbers;
        unsigned int        size;

    public:
        Span(void);
        Span(unsigned int N);
        Span(const Span &source);

        Span& operator=(const Span &source);

        void    addNumber(int num);

        template <typename it>
        void    addNumber(it begin, it end)
        {
            if (std::distance(begin, end) + numbers.size() > size)
                throw (std::out_of_range("cant add number to vector."));
            numbers.insert(numbers.end(), begin, end);
        };

        const std::vector<int>& getvec(void) const;

        int     shortestSpan(void) const;
        int     longestSpan(void) const;

        ~Span(void);
};

#endif
