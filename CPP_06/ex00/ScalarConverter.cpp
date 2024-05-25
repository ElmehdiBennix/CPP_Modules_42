#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal) throw()
{
    if (isInt(literal))
    {
        std::cout << "int up:" << std::endl;
        convertFromInt(literal);
    }
    else if (isFloat(literal))
    {
        std::cout << "flaot up:" << std::endl;
        convertFromFloat(literal);
    }
    else if (isDouble(literal))
    {
        std::cout << "double up:" << std::endl;
        convertFromDouble(literal);
    }
    else
        std::cerr << "Error: Unrecognized Format." << std::endl;
};

// bool ScalarConverter::isChar(const std::string &type) throw()
// {
//     return (type.length() == 3 && type[0] == '\'' && type[2] == '\'');
// };

// bool ScalarConverter::isInt(const std::string &type)
// {
//     try {
//         long long val = std::stoll(type);
//         if (val < INT_MIN || val > INT_MAX) {
//             return false;
//         }
//     } catch (const std::invalid_argument& e) {
//         return false;
//     } catch (const std::out_of_range& e) {
//         return false;
//     }
//     return true;
// }

bool ScalarConverter::isInt(const std::string &type) throw()
{
    std::size_t i = 0;

    if (type[i] == '-' || type[i] == '+')
        i++;
    for (; i < type.length(); i++)
    {
        if (!std::isdigit(type[i]))
            return false;
    }
    return (i > 1);
};

bool ScalarConverter::isFloat(const std::string &type) throw()
{
    int dot = 0;
    std::size_t i = 0;

    if (type == "-inff" || type == "+inff" || type == "nanf")
        return true;

    if (type[i] == '-' || type[i] == '+')
        i++;
    for (; i < type.length() - 1; i++)
    {
        if (type[i] == '.')
        {
            dot++;
            i++;
        }
        if (!type[i] || !std::isdigit(type[i]))
            return false;
    }
    return (i > 1 && type[i] == 'f' && dot == 1);
};

bool ScalarConverter::isDouble(const std::string &type) throw()
{
    int dot = 0;
    std::size_t i = 0;

    if (type == "-inf" || type == "+inf" || type == "nan")
        return true;

    if (type[i] == '-' || type[i] == '+')
        i++;

    for (; i < type.length(); i++)
    {
        if (type[i] == '.')
        {
            dot++;
            i++;
        }
        if (!type[i] || !std::isdigit(type[i]))
            return false;
    }
    return (i > 1 && dot == 1);
};

void ScalarConverter::convertFromInt(const std::string& literal) throw()
{
    long num = 0;

    if (literal.length() > 11 || (num = std::atol(literal.c_str())) > INT_MAX || num < INT_MIN )
    {
        std::cerr << "Error: Convertion failure overflow." << std::endl;
        return;
    }

    if (num >= 32 && num <= 126)
        std::cout << "char: \'" << static_cast<char>(num) << "\'" << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
};

void ScalarConverter::convertFromFloat(const std::string& literal) throw()
{
    float x = std::atof(literal.c_str());

    if (x >= 32 && x <= 126)
        std::cout << "char: \'" << static_cast<char>(x) << "\'" << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(x) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << x << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(x) << std::endl;
};

void ScalarConverter::convertFromDouble(const std::string& literal) throw()
{
    double x = std::atof(literal.c_str());

    if (x >= 32 && x <= 126)
        std::cout << "char: \'" << static_cast<char>(x) << "\'" << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(x) << std::endl;
    std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(x) << "f" << std::endl;
    std::cout << "double: " << x << std::endl;
};