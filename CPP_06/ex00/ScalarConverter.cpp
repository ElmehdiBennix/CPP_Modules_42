#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& literal) throw()
{
    if (isInt(literal))
    {
        // check for overflow

    }
    else if (isFloat(literal))
    {
        // check for overflow
    }
    else if (isDouble(literal))
    {
        // check for overflow
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
    for (i; i < type.length(); i++)
    {
        if (!std::isdigit(type[i]))
            return false;
    }
    return true;
};

bool ScalarConverter::isFloat(const std::string &type) throw()
{
    int dot = 0;
    std::size_t i = 0;

    if (type == "-inff" || type == "+inff" || type == "nanf")
        return true;

    if (type[i] == '-' || type[i] == '+')
        i++;
    for (i; i < type.length() - 1; i++)
    {
        if (type[i] == '.')
            dot++;
        else if (!std::isdigit(type[i]))
            return false;
    }
    return (type[i] == 'f' && dot == 1);
};

bool ScalarConverter::isDouble(const std::string &type) throw()
{
    int dot = 0;
    std::size_t i = 0;

    if (type == "-inf" || type == "+inf" || type == "nan")
        return true;

    if (type[i] == '-' || type[i] == '+')
        i++;
    for (i; i < type.length(); i++)
    {
        if (type[i] == '.')
            dot++;
        else if (!std::isdigit(type[i]))
            return false;
    }
    return (dot == 1);
};

// void ScalarConverter::convertFromChar(char c) throw()
// {

// };

void ScalarConverter::convertFromInt(int i) throw()
{

};

void ScalarConverter::convertFromFloat(float f) throw()
{

};

void ScalarConverter::convertFromDouble(double d) throw()
{

};