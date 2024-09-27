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


template < typename Tseq, typename Tchain >
class PmergeMe
{
    private:

    private:
        int     getToken(char *arg)
        {
            int                 number;
            std::stringstream   oss(arg);

            for (size_t i = 0; arg[i]; i++)
            {
                if (!std::isdigit(arg[i]))
                    throw std::invalid_argument("Error: invalid token.");
            }

            if (!(oss >> number))
                throw std::invalid_argument("Error: invalid conversion to int.");

            return (number);
        };

    public:
        Tseq        container;
        Tchain      mainChain;
        Tchain      pendchain;
        int         struggler;

        bool        sorted;
        clock_t     time;


        typedef typename Tseq::iterator       iterator;
        typedef typename Tseq::const_iterator const_iterator;

        PmergeMe(void);

        PmergeMe(char **av) : struggler(-1) , sorted(false), time(0)
        {
            Tchain  numbers;

            for (size_t i = 1; av[i]; i++) // check for dups
                numbers.push_back(getToken(av[i]));

            if (numbers.size() % 2 != 0)
            {
                struggler = *(--numbers.end());
                numbers.erase(--numbers.end());
            }

            // int x = 0;
            for (size_t i = 0; i < numbers.size(); i+=2)
                container.push_back(std::pair<int, int>(numbers[i], numbers[i + 1]));
            // {
                // std::cout << numbers[i] << " " << numbers[i + 1] << std::endl;
                // std::cout << container[x].first << " " << container[x].second << std::endl;
                // x++;
            // }
        };

        PmergeMe(const PmergeMe& source)
        {
            *this = source;
        };

        PmergeMe&       operator=(const PmergeMe& source)
        {
            if (this != &source)
            {

            }
            return (*this);
        };

        void    print(void)
        {
            if (!sorted)
            {
                COUT("Before:  " << RESET << *this);
            }
            else
            {
                COUT("After:   " << RESET);
            }

        };

        void    fordJohnsonAlgorithm()
        {
            time = clock();

            // swap pairs all small elements must go to the right side
            for (size_t i = 0; i < container.size(); i++)
            {
                if (container[i].first < container[i].second)
                {
                    std::swap(container[i].first, container[i].second);
                    std::cout << container[i].first << " " << container[i].second << std::endl;
                }
                else
                    std::cout << container[i].first << " " << container[i].second << std::endl;
            }
            std::cout << "<========================================>" << std::endl;
            // sorting the main chain pairs
            std::sort(container.begin(), container.end());
            std::cout << *this << std::endl;
            std::cout << "<========================================>" << std::endl;
            // now we can separate the pairs to main and pend chains
            for (size_t i = 0; i < container.size(); i++)
            {
                mainChain.push_back(container[i].first);
                pendchain.push_back(container[i].second);
            }
            std::cout << "<========================================>" << std::endl;
            //pushing first element in the pend to the main chain
            mainChain.insert(mainChain.begin(), *pendchain.begin());
            pendchain.erase(pendchain.begin());
            for (size_t i = 0; i < mainChain.size(); i++)
                std::cout << mainChain[i] << " ";
            std::cout << std::endl;
            for (size_t i = 0; i < pendchain.size(); i++)
                std::cout << pendchain[i] << " ";
            std::cout << std::endl;
            // std::cout << mainChain << std::endl;
            // std::cout << pendchain << std::endl;
            std::cout << "<========================================>" << std::endl;
            // jacobsthal seq



        };

        ~PmergeMe(void)
        {
        };
};

template < typename Tseq, typename Tchain >
std::ostream&   operator<<(std::ostream& os, const PmergeMe<Tseq, Tchain> &type)
{
    for (size_t i = 0; i < type.container.size() ; i++)
        os << type.container[i].first << " " << type.container[i].second << " ";

    if (type.struggler != -1)
        os << type.struggler;
    return os;
};


// template<typename T>
// std::ostream&       operator<<(std::ostream &os, const std::vector<T> &type)
// {
//     for (size_t i = 0; i < type.size(); ++i)
//         os << type[i] << " ";
//     return os;
// };

// template<typename T>
// std::ostream&       operator<<(std::ostream &os, const std::deque<T> &type)
// {
//     for (size_t i = 0; i < type.size(); ++i)
//         os << type[i] << " ";
//     return os;
// };

#endif
