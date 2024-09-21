#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void)
{
};

ScalarConverter::ScalarConverter(const ScalarConverter& source)
{
};


ScalarConverter&
ScalarConverter::operator=(const ScalarConverter& source)
{
};

ScalarConverter::~ScalarConverter(void)
{
};


static bool pseudo(const std::string& type) throw()
{
    if (type == "-inff" || type == "+inff" || type == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << type << std::endl;
        std::cout << "double: " << type.substr(0, type.length() - 1) << std::endl;
        return (true);
    }
    else if (type == "-inf" || type == "+inf" || type == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << type << "f" << std::endl;
        std::cout << "double: " << type << std::endl;
        return (true);
    }
    return (false);
};

static bool isInt(const std::string &type) throw()
{
    std::size_t i = 0;

    if (type[i] == '-' || type[i] == '+')
        i++;
    if (!type[i])
        return false;
    else
    {
        for (; i < type.length(); i++)
        {
            if (!std::isdigit(type[i]))
                return false;
        }
    }
    return true;
};

static bool isFloat(const std::string &type) throw()
{
    int dot = 0;
    std::size_t i = 0;

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

static bool isDouble(const std::string &type) throw()
{
    int dot = 0;
    std::size_t i = 0;

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

static void convertFromChar(const std::string& literal) throw()
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

static void convertFromInt(const std::string& literal) throw()
{
    int num = 0;
    std::stringstream extract(literal);

    if (!(extract >> num))
        std::cerr << "Error: int conversion is impossible." << std::endl;
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

static void convertFromFloat(const std::string& literal) throw()
{
    float num = 0;
    std::stringstream extract(literal.substr(0, literal.length() - 1));

    if (!(extract >> num))
        std::cerr << "Error: float conversion impossible." << std::endl;
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

static void convertFromDouble(const std::string& literal) throw()
{
    double num = 0;
    std::stringstream extract(literal);

    if (!(extract >> num))
        std::cerr << "Error: double conversion impossible." << std::endl;
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

void
ScalarConverter::convert(const std::string& literal) throw()
{
    std::cout << std::fixed << std::setprecision(1);

    if (pseudo(literal))
        return;
    if (isInt(literal))
        convertFromInt(literal);
    else if (isFloat(literal))
        convertFromFloat(literal);
    else if (isDouble(literal))
        convertFromDouble(literal);
    else if (literal.length() == 1)
        convertFromChar(literal);
    else
        std::cerr << "Error: Unrecognized Format." << std::endl;
};
