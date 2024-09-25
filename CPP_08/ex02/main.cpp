#include "MutantStack.hpp"
#include <list>

// int main()
// {
//     MutantStack<int> mstack;

//     mstack.push(5);
//     mstack.push(17);

//     std::cout << mstack.top() << std::endl;

//     mstack.pop();

//     std::cout << mstack.size() << std::endl;

//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     mstack.push(0);

//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();

//     ++it;
//     --it;

//     while (it != ite) {
//         std::cout << *it << std::endl;
//         ++it;
//     }

//     std::stack<int> s(mstack);

//     std::cout << "<========================================>" << std::endl;

//     std::list<int> llist;

//     llist.push_back(5);
//     llist.push_back(17);

//     std::cout << llist.back() << std::endl;

//     llist.pop_back();

//     std::cout << llist.size() << std::endl;

//     llist.push_back(3);
//     llist.push_back(5);
//     llist.push_back(737);
//     llist.push_back(0);

//     std::list<int>::iterator iti = llist.begin();
//     std::list<int>::iterator itee = llist.end();

//     ++iti;
//     --iti;

//     while (iti != itee) {
//         std::cout << *iti << std::endl;
//         ++iti;
//     }

//     return 0;
// }

void testPushPop()
{
    MutantStack<int> mStack;

    mStack.push(10);
    mStack.push(20);

    if (mStack.top() != 20) {
        std::cerr << "Error: Top element should be 20" << std::endl;
    }

    mStack.pop();

    if (mStack.top() != 10) {
        std::cerr << "Error: Top element should be 10" << std::endl;
    }

    mStack.pop();

    try {
        mStack.top();
        std::cerr << "Error: Exception should be thrown when accessing top of empty stack" << std::endl;
    } catch (const std::out_of_range&) {
        std::cout << "Passed: Exception correctly thrown on empty stack" << std::endl;
    } catch (...) {
        std::cerr << "Error: Unexpected exception type thrown" << std::endl;
    }
}

void testIteration()
{
    MutantStack<int> mStack;

    mStack.push(1);
    mStack.push(2);
    mStack.push(3);

    int sum = 0;
    for (MutantStack<int>::iterator it = mStack.begin(); it != mStack.end(); ++it) {
        sum += *it;
    }

    if (sum != 6) {
        std::cerr << "Error: Sum should be 6, got " << sum << std::endl;
    } else {
        std::cout << "Passed: Sum is correct" << std::endl;
    }
}

void testCopyConstructor()
{
    MutantStack<int> original;
    original.push(1);
    original.push(2);

    MutantStack<int> copy(original);
    if (copy.top() != 2) {
        std::cerr << "Error: Copy top should be 2" << std::endl;
    } else {
        std::cout << "Passed: Copy constructor works correctly" << std::endl;
    }
}

void testAssignmentOperator()
{
    MutantStack<int> original;
    original.push(1);
    original.push(2);

    MutantStack<int> assigned;
    assigned = original;
    if (assigned.top() != 2) {
        std::cerr << "Error: Assigned top should be 2" << std::endl;
    } else {
        std::cout << "Passed: Assignment operator works correctly" << std::endl;
    }
}

int main()
{
    testPushPop();
    testIteration();
    testCopyConstructor();
    testAssignmentOperator();

    return 0;
}
