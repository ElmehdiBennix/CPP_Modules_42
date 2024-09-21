#include "RPN.hpp"

RPN::RPN(void)
{
};

RPN::RPN(const RPN& source)
{
    (void) source;
};

RPN&
RPN::operator=(const RPN& source)
{
    (void) source;
    return (*this);
};

RPN::~RPN(void)
{
};

void
RPN::calculatePostFix(const std::string& expression)
{
    std::stack<int> numbers;
    std::istringstream istream(expression);
    std::string        token;

    while(istream >> token)
    {
        std::cout << token << std::endl;

        if (token.size() == 1 && token[0] >= 48 && token[0] <= 57)
            numbers.push(token[0] - '0');
        else if (token.size() == 1 && TOKENS(token[0]))
        {
            if (numbers.size() < 2)
                throw (std::runtime_error("Error: missing operation."));

            int result;
            int b = numbers.top(); numbers.pop();
            int a = numbers.top(); numbers.pop();

            switch (token[0])
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    if (b == 0)
                        throw (std::runtime_error("Error: division by zero impossible."));
                    result = a / b;
                    break;
            }
            numbers.push(result);
        }
        else
            throw (std::runtime_error("Error: bad input."));
    }

    if (numbers.size() == 1)
        COUT(numbers.top());
    else
        throw (std::runtime_error("Error: missing operation."));
};
