#include "PmergeMe.hpp"

PmergeMeVector::PmergeMeVector(void)
{
};

PmergeMeVector::PmergeMeVector(std::vector<int> numbers) : struggler(-1) , sorted(false), start(0)
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
        this->sorted = source.sorted;
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
PmergeMeVector::insertUsingBinarySearch(std::vector<int>& sortedlist, int element)
{
    // Use std::lower_bound to find the insertion point
    std::vector<int>::iterator it = std::lower_bound(sortedlist.begin(), sortedlist.end(), element);

    // Insert the element at the correct position
    sortedlist.insert(it, element);
};

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

    // pushing first element in the pend to the main chain
    mainChain.insert(mainChain.begin(), *pendchain.begin());
    pendchain.erase(pendchain.begin());

    // Insertion using binary search and Jacobsthal strategy
    for (size_t i = 0; i < pendchain.size(); i++)
        insertUsingBinarySearch(mainChain, pendchain[i]);
    pendchain.clear();
};

bool
PmergeMeVector::isSorted(bool print)
{
    for (size_t i = 0; i < mainChain.size() - 1; i++)
    {
        if (mainChain[i] > mainChain[i + 1])
        {
            if (print == true)
                std::cout << RED << "ERROR" << std::endl;
            return false;
        }
    }
    sorted = true;
    if (print == true)
            std::cout << GREEN << "PASSED" << std::endl;
    return true;
};

PmergeMeVector::~PmergeMeVector(void)
{
};

//##############################################################################//

PmergeMeDeque::PmergeMeDeque(void)
{
};

PmergeMeDeque::PmergeMeDeque(std::vector<int> numbers) : struggler(-1) , sorted(false), start(0)
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
        this->sorted = source.sorted;
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
PmergeMeDeque::insertUsingBinarySearch(std::deque<int>& sortedlist, int element)
{
    // Use std::lower_bound to find the insertion point
    std::deque<int>::iterator it = std::lower_bound(sortedlist.begin(), sortedlist.end(), element);

    // Insert the element at the correct position
    sortedlist.insert(it, element);
};

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

    // pushing first element in the pend to the main chain
    mainChain.insert(mainChain.begin(), *pendchain.begin());
    pendchain.erase(pendchain.begin());

    // Insertion using binary search and Jacobsthal strategy
    for (size_t i = 0; i < pendchain.size(); i++)
    {
        insertUsingBinarySearch(mainChain, pendchain[i]);
        pendchain.erase(pendchain.begin() + i);
    }
    pendchain.clear();
};

bool
PmergeMeDeque::isSorted(bool print)
{
    for (size_t i = 0; i < mainChain.size() - 1; i++)
    {
        if (mainChain[i] > mainChain[i + 1])
        {
            if (print == true)
                std::cout << RED << "ERROR" << std::endl;
            return false;
        }
    }
    sorted = true;
    if (print == true)
            std::cout << GREEN << "PASSED" << std::endl;
    return true;
};

PmergeMeDeque::~PmergeMeDeque(void)
{
};
