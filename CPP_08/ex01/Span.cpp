#include "Span.hpp"

Span::Span(void) : size(1)
{
    numbers.reserve(1);
};

Span::Span(unsigned int N) : size(N)
{
    numbers.reserve(N);
};

Span::Span(const Span &source)
{
    *this = source;
};

Span&
Span::operator=(const Span &source)
{
    if (this != &source)
    {
        numbers.resize(source.size);
        std::copy(source.numbers.begin(), source.numbers.end(), this->numbers.begin());
        size = source.size;
    }
    return (*this);
};

std::vector<int>*
Span::getvec(void)
{
    return &numbers;
};

void
Span::addNumber(int num)
{
    if (numbers.size() >= size)
        throw (std::out_of_range("vector is full."));
    numbers.push_back(num);
};

int
Span::shortestSpan(void) const
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
};

int
Span::longestSpan(void) const
{
    if (numbers.size() < 2)
        throw std::logic_error("Can't find the span. Fill in more numbers.");

    std::vector<int> sorted_vec(numbers);
    std::sort(sorted_vec.begin(), sorted_vec.end());

    return (*(sorted_vec.end() - 1) - *sorted_vec.begin());
};

Span::~Span(void)
{
};
