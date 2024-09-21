#if !defined(PMERGEME_HPP__)
#define PMERGEME_HPP__

#include <iostream>
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

class PmergeMe
{
    private:
        PmergeMe(void);
        PmergeMe(const PmergeMe& source);
        PmergeMe&   operator=(const PmergeMe& source);
        ~PmergeMe(void);

    public:


};

#endif
