#if !defined(MUTANTSTACK_HPP__)
#define MUTANTSTACK_HPP__

#include <iostream>
#include <deque>
#include <stack>

template <typename T, typename seq = std::deque<T> >
class MutantStack : public std::stack<T, seq>
{
    public:
        MutantStack(void) : std::stack<T,seq>()
        {};

        MutantStack(const MutantStack &source) : std::stack<T,seq>(source)
        {};

        MutantStack& operator=(const MutantStack& source)
        {
            if (this != &source)
                std::stack<T, seq>::operator=(source);
            return (*this);
        };

        typedef typename seq::iterator iterator;
        typedef typename seq::const_iterator const_iterator;

        iterator begin(void)
        {
            return this->c.begin();
        };

        const_iterator begin(void) const
        {
            return this->c.begin();
        };

        iterator end(void)
        {
            return this->c.end();
        };

        const_iterator end(void) const
        {
            return this->c.end();
        };

        ~MutantStack(void)
        {};
};

#endif
