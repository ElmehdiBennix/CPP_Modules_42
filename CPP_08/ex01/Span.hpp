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
        Span(void) : size(1)
        {
            numbers.reserve(1);
        };

        Span(unsigned int N) : size(N)
        {
            numbers.reserve(N);
        };

        Span(const Span &source)
        {
            *this = source;
        };

        Span& operator=(const Span &source)
        {
            if (this != &source)
            {
                numbers.resize(source.size);
                std::copy(source.numbers.begin(), source.numbers.end(), this->numbers.begin());
                size = source.size;
            }
            return (*this);
        };

        void    addNumber(int num)
        {
            if (numbers.size() >= size)
                throw (std::out_of_range("vector is full."));
            numbers.push_back(num);
        };

        template<typename it>
        void    addNumber(it begin, it end)
        {
            if (std::distance(begin, end) + numbers.size() >= size)
                throw (std::out_of_range("vector is full."));
            numbers.insert(numbers.end(), begin, end);
        };

        std::vector<int>* getvec(void)
        {
            return &numbers;
        };

        int shortestSpan(void) const
        {
            if (numbers.size() < 2)
                throw std::logic_error("Can't find the span. Fill in more numbers.");

            std::vector<int> sorted_vec(numbers);
            std::sort(sorted_vec.begin(), sorted_vec.end());

            int span = 2147483647;

            for (std::vector<int>::const_iterator it = sorted_vec.begin() + 1; it != sorted_vec.end(); ++it) {
                int tmp = *it - *(it - 1);
                if (tmp < span)
                    span = tmp;
            }
            return span;
        }

        int longestSpan(void) const
        {
            if (numbers.size() < 2)
                throw std::logic_error("Can't find the span. Fill in more numbers.");

            std::vector<int> sorted_vec(numbers);
            std::sort(sorted_vec.begin(), sorted_vec.end());

            return (*(sorted_vec.end() - 1) - *sorted_vec.begin());
        }

        ~Span(void)
        {
        };
};

#endif
