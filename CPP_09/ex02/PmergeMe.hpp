#if !defined(PMERGEME_HPP__)
#define PMERGEME_HPP__

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

#define COUT(out) std::cout << GREEN << out << RESET << std::endl
#define CWAR(out) std::cout << YELLOW << out << RESET << std::endl
#define CERR(out) std::cerr << RED << out << RESET << std::endl

class PmergeMeVector
{
    private:
        std::vector<std::pair<int, int> >  container;
        std::vector<int>                   mainChain;
        std::vector<int>                   pendchain;
        int                                struggler;
        clock_t                            start;

    private:
        PmergeMeVector(void);
        PmergeMeVector(const PmergeMeVector& source);

        PmergeMeVector&       operator=(const PmergeMeVector& source);

    public:
        PmergeMeVector(std::vector<int> numbers);

        const std::vector<int>& getMainChain() const;
        clock_t                 getStart() const;

        void    fordJohnsonAlgorithm();
        void    isSorted(void) const;

        ~PmergeMeVector(void);
};

class PmergeMeDeque
{
    private:
        std::deque<std::pair<int, int> >  container;
        std::deque<int>                   mainChain;
        std::deque<int>                   pendchain;
        int                               struggler;
        clock_t                           start;

    private:
        PmergeMeDeque(void);
        PmergeMeDeque(const PmergeMeDeque& source);

        PmergeMeDeque&       operator=(const PmergeMeDeque& source);

    public:
        PmergeMeDeque(std::vector<int> numbers);

        const std::deque<int>&  getMainChain() const;
        clock_t                 getStart() const;

        void    fordJohnsonAlgorithm();
        void    isSorted(void) const;

        ~PmergeMeDeque(void);
};


// std::vector<size_t>     calculateJacobSthal(size_t n);

template <typename T>
std::ostream&   operator<<(std::ostream&    os, const  std::vector<T>& type)
{
    for (size_t i = 0; i < type.size(); i++)
        os << type[i] << " ";
    return os;
};

template <typename T>
std::ostream&   operator<<(std::ostream&    os, const  std::deque<T>& type)
{
    for (size_t i = 0; i < type.size(); i++)
        os << type[i] << " ";
    return os;
};

#endif
