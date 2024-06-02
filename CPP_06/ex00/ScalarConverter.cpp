#include "ScalarConverter.hpp"

bool isInt(const std::string &type) throw()
{
    std::size_t i = 0;

    if (type[i] == '-' || type[i] == '+')
        i++;
    if (!type[i])
        return false;
    else {
        for (; i < type.length(); i++) {
            if (!std::isdigit(type[i]))
                return false;
        }
    }
    return true;
};

bool isFloat(const std::string &type) throw()
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
    return (i >= 3 && type[i] == 'f' && dot == 1);
};

bool isDouble(const std::string &type) throw()
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
    return (i >= 3 && dot == 1);
};

void convertFromChar(const std::string& literal) throw()
{
    char num = literal[0];

    if (num >= 32 && num <= 126)
        std::cout << "char: \'" << static_cast<char>(num) << "\'" << std::endl;
    else 
        std::cout << "char:  Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(num) << std::endl;
    std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(num) << std::endl;
};

void convertFromInt(const std::string& literal) throw()
{
    int num = 0;
    std::stringstream extract(literal);

    if (!(extract >> num))
    {
        std::cerr << "Error: int conversion failed" << std::endl;
        return;
    }
    else
    {
        if (num >= 32 && num <= 126)
            std::cout << "char: \'" << static_cast<char>(num) << "\'" << std::endl;
        else if (num >= 0 && num <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (std::isnan(num) || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(num) << std::endl;
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << std::endl;
    }
};

void convertFromFloat(const std::string& literal) throw()
{
    float num = 0;
    std::stringstream extract(literal.substr(0, literal.length() - 1));

    if (!(extract >> num))
    {
        std::cerr << "Error: float conversion failed." << std::endl;
        return;
    }
    else
    {
        if (num >= 32 && num <= 126)
            std::cout << "char: \'" << static_cast<char>(num) << "\'" << std::endl;
        else if (num >= 0 && num <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (std::isnan(num) || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(num) << std::endl;
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << std::endl;
    }
};

void convertFromDouble(const std::string& literal) throw()
{
    double num = 0;
    std::stringstream extract(literal);

    if (!(extract >> num))
    {
        std::cerr << "Error: double conversion failed" << std::endl;
        return;
    }
    else
    {
        if (num >= 32 && num <= 126)
            std::cout << "char: \'" << static_cast<char>(num) << "\'" << std::endl;
        else if (num >= 0 && num <= 127)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: impossible" << std::endl;
        if (std::isnan(num) || num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(num) << std::endl;
        std::cout << "float: " << static_cast<float>(num) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(num) << std::endl;
    }
};

void ScalarConverter::convert(const std::string& literal) throw()
{
    if (literal.length() == 1)
    {
        std::cout << "=> char up:" << std::endl;
        convertFromChar(literal);
    }
    else if (isInt(literal))
    {
        std::cout << "=> int up:" << std::endl;
        convertFromInt(literal);
    }
    else if (isFloat(literal))
    {
        std::cout << "=> float up:" << std::endl;
        convertFromFloat(literal);
    }
    else if (isDouble(literal))
    {
        std::cout << "=> double up:" << std::endl;
        convertFromDouble(literal);
    }
    else
        std::cerr << "Error: Unrecognized Format." << std::endl;
};