#if !(defined MUTANTSTACK_HPP__)
#define MUTANTSTACK_HPP__

#include <iostream>
#include <deque>
#include <stack>
#include <list>

// template<typename T, typename sequence = std::deque<T>>
template<typename T, typename seq = std::deque<T>>
class MutantStack : public std::stack<T, seq> {

    public:
        typedef typename std::deque<int>::iterator iterator;
        typedef typename std::deque<int>::const_iterator const_iterator;
        
        MutantStack(void) : std::stack<T,seq>() {};
        MutantStack(const MutantStack &source) : std::stack<T,seq>(source) {};

        // operator = 

        iterator begin(void) {
            return this->c.begin();
        };

        const_iterator begin(void) const {
            return this->c.begin();
        };

        iterator end(void) {
            return this->c.end();
        };

        const_iterator end(void) const {
            return this->c.end(); 
        };

        ~MutantStack() {};
};

#endif