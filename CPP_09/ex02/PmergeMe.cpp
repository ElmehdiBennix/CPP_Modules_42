#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector(void)
{
};

PmergeMeVector::PmergeMeVector(std::vector<int> numbers) : struggler(-1),start(0)
{
    if (numbers.size() % 2 != 0)
    {
        struggler = *(--numbers.end());
        numbers.erase(--numbers.end());
    }

    for (size_t i = 0; i < numbers.size(); i+=2)
        container.push_back(std::pair<int, int>(numbers[i], numbers[i + 1]));
};

PmergeMeVector::PmergeMeVector(const PmergeMeVector& source)
{
    *this = source;
};

PmergeMeVector&
PmergeMeVector::operator=(const PmergeMeVector& source)
{
    if (this != &source)
    {
        this->container = source.container;
        this->mainChain = source.mainChain;
        this->pendchain = source.pendchain;
        this->pendchain = source.pendchain;
        this->start = source.start;
    }
    return (*this);
};


clock_t
PmergeMeVector::getStart() const
{
    return start;
}

const std::vector<int>&
PmergeMeVector::getMainChain() const
{
    return mainChain;
}

void
PmergeMeVector::fordJohnsonAlgorithm()
{
    start = clock();

    // swap pairs all small elements must go to the right side
    for (size_t i = 0; i < container.size(); i++)
    {
        if (container[i].first < container[i].second)
            std::swap(container[i].first, container[i].second);
    }

    // sorting the main chain pairs
    std::sort(container.begin(), container.end());

    // now we can separate the pairs to main and pend chains
    for (size_t i = 0; i < container.size(); i++)
    {
        mainChain.push_back(container[i].first);
        pendchain.push_back(container[i].second);
    }
    if (struggler != -1)
        pendchain.push_back(struggler);

    if (pendchain.empty())
        return;

    // pushing first element in the pend to the main chain
    mainChain.insert(mainChain.begin(), *pendchain.begin());
    pendchain.erase(pendchain.begin());

    for (size_t i = 0; i < pendchain.size(); i++)
    {
        std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendchain[i]);
        mainChain.insert(it, pendchain[i]);
    }
    pendchain.clear();
};

void
PmergeMeVector::isSorted(void) const
{
    for (size_t i = 1; i < mainChain.size(); ++i)
    {
        if (mainChain[i - 1] > mainChain[i])
        {
            std::cout << RED << "ERROR" << std::endl;
            return;
        }
    }
    std::cout << GREEN << "PASSED" << std::endl;
};

PmergeMeVector::~PmergeMeVector(void)
{
};

//##############################################################################//

PmergeMeDeque::PmergeMeDeque(void)
{
};

PmergeMeDeque::PmergeMeDeque(std::vector<int> numbers) : struggler(-1) , start(0)
{
    if (numbers.size() % 2 != 0)
    {
        struggler = *(--numbers.end());
        numbers.erase(--numbers.end());
    }

    for (size_t i = 0; i < numbers.size(); i+=2)
        container.push_back(std::pair<int, int>(numbers[i], numbers[i + 1]));
};

PmergeMeDeque::PmergeMeDeque(const PmergeMeDeque& source)
{
    *this = source;
};

PmergeMeDeque&
PmergeMeDeque::operator=(const PmergeMeDeque& source)
{
    if (this != &source)
    {
        this->container = source.container;
        this->mainChain = source.mainChain;
        this->pendchain = source.pendchain;
        this->pendchain = source.pendchain;
        this->start = source.start;
    }
    return (*this);
};


clock_t
PmergeMeDeque::getStart() const
{
    return start;
}

const std::deque<int>&
PmergeMeDeque::getMainChain() const
{
    return mainChain;
}

void
PmergeMeDeque::fordJohnsonAlgorithm()
{
    start = clock();

    // swap pairs all small elements must go to the right side
    for (size_t i = 0; i < container.size(); i++)
    {
        if (container[i].first < container[i].second)
            std::swap(container[i].first, container[i].second);
    }

    // sorting the main chain pairs
    std::sort(container.begin(), container.end());

    // now we can separate the pairs to main and pend chains
    for (size_t i = 0; i < container.size(); i++)
    {
        mainChain.push_back(container[i].first);
        pendchain.push_back(container[i].second);
    }
    if (struggler != -1)
        pendchain.push_back(struggler);

    if (pendchain.empty())
        return;

    // pushing first element in the pend to the main chain
    mainChain.insert(mainChain.begin(), *pendchain.begin());
    pendchain.erase(pendchain.begin());

    for (size_t i = 0; i < pendchain.size(); i++)
    {
        std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), pendchain[i]);
        mainChain.insert(it, pendchain[i]);
    }
    pendchain.clear();
};

void
PmergeMeDeque::isSorted(void) const
{
    for (size_t i = 1; i < mainChain.size(); ++i)
    {
        if (mainChain[i - 1] > mainChain[i])
        {
            std::cout << RED << "ERROR" << std::endl;
            return;
        }
    }
    std::cout << GREEN << "PASSED" << std::endl;
};

PmergeMeDeque::~PmergeMeDeque(void)
{
};


// std::vector<size_t>     calculateJacobSthal(size_t n)
// {
//     std::vector<size_t> jacobsthalSeq;

//     // Base cases
//     jacobsthalSeq.push_back(0); // if pair else comment else uncomment
//     if (n == 0)
//         return (jacobsthalSeq);

//     jacobsthalSeq.push_back(1);
//     if (n == 1)
//         return (jacobsthalSeq);

//     // Generate the sequence up to n
//     for (size_t i = 2; i < n; i++)
//     {
//         size_t nextJacobsthal = jacobsthalSeq[i - 1] + 2 * jacobsthalSeq[i - 2];
//         jacobsthalSeq.push_back(nextJacobsthal);
//     }
//     // jacobsthalSeq.erase(jacobsthalSeq.begin());
//     return (jacobsthalSeq);
// };
