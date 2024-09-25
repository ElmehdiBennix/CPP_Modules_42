#include "MutantStack.hpp"

void    iteration()
{
    MutantStack<int> mStack;

    mStack.push(1);
    mStack.push(2);
    mStack.push(3);

    int sum = 0;
    for (MutantStack<int>::iterator it = mStack.begin(); it != mStack.end(); ++it)
        sum += *it;

    if (sum != 6)
        std::cerr << "Error: Sum should be 6, got " << sum << std::endl;
    else
        std::cout << "Passed: Sum is correct" << std::endl;
}

void    copyConstructor()
{
    MutantStack<int> original;
    original.push(1);
    original.push(2);

    MutantStack<int> copy(original);
    if (copy.top() != 2)
        std::cerr << "Error: Copy top should be 2" << std::endl;
    else
        std::cout << "Passed: Copy constructor works correctly" << std::endl;
}

void    assignmentOperator()
{
    MutantStack<int> original;
    original.push(1);
    original.push(2);

    MutantStack<int> assigned;
    assigned = original;
    if (assigned.top() != 2)
        std::cerr << "Error: Assigned top should be 2" << std::endl;
    else
        std::cout << "Passed: Assignment operator works correctly" << std::endl;
}

void    sizeContainer()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    mstack.pop();
    mstack.push(3);
    mstack.push(5);
    mstack.pop();
    mstack.push(737);
    mstack.push(0);
    mstack.pop();

    if (mstack.size() != 3)
        std::cerr << "Error: size should be 3" << std::endl;
    else
        std::cout << "Passed: size is correct" << std::endl;
}

int main()
{
    try
    {
        iteration();
        copyConstructor();
        assignmentOperator();
        sizeContainer();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
