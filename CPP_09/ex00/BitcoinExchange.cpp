
#include "BitcoinExchange.hpp"

Bitcoin::Bitcoin(void)
{
    std::size_t  i = 0;
    std::string dataInput(DATA_FILE);

    if ((i = dataInput.find(".csv")) == std::string::npos || i + 4 != dataInput.length()) {
        throw (std::runtime_error("Error: File " + std::string(DATA_FILE) + " must end with .csv format"));
    }

    std::ifstream  dataFile(DATA_FILE, std::ios_base::in);
    if (!dataFile.is_open())
        throw (std::runtime_error("Error: Failed to open " DATA_FILE "."));

    if (!parseCsv(dataFile)) {
        dataFile.close();
        throw (std::runtime_error("Error: Failed to load database '" DATA_FILE "'"));
    }

    dataFile.close();
};

Bitcoin::Bitcoin(const Bitcoin& source)
{
    *this = source;
};

Bitcoin&
Bitcoin::operator=(const Bitcoin &source)
{
    if (this != &source)
        dataBase = source.dataBase;
    return (*this);
};

int
Bitcoin::parseDate(const std::string &date) const
{
    std::istringstream tokens(date);

    if (date.length() != 10)
        return BADINPUT;


    if (date[4] != '-' || date[7] != '-')
        return BADINPUT;

    int  year, month, day;
    char dash[2];

    if (!(tokens >> year >> dash[0] >> month >> dash[1] >> day))
        return BADINPUT;

    if (dash[0] != '-' || dash[1] != '-')
        return BADINPUT;

    if (1 > month || month > 12 || 1 > day || day > 31)
        return BADINPUT;

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return BADINPUT;

    // if (month == 2) {
    //     bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    //     if (day > 29 || (day == 29 && !isLeapYear)) {
    //         return BADINPUT;
    //     }
    // }

    std::string val(date);
    val.erase(val.find_first_of('-'), 1);
    val.erase(val.find_first_of('-'), 1);

    return (atoi(val.c_str()));
};

float
Bitcoin::parseValue(const std::string &value, float min, float max) const
{
    float number;
    char  remaining;
    std::istringstream token(value);

    if (!(token >> number) || token >> remaining)
        return BADINPUT;

    if (number < min)
        return NEGATIVE;

    if (number > max || number != number || number == std::numeric_limits<float>::infinity() || number == -std::numeric_limits<float>::infinity())
        return OVERLIMIT;

    return number;
};

bool
Bitcoin::parseCsv(std::ifstream &dataFile)
{
    std::string line;

    for (size_t i = 0; std::getline(dataFile, line); i++)
    {
        size_t pos = line.find(",");
        if (pos == std::string::npos)
            return false;

        int   date = 0;
        float rate = 0;
        std::string lvalue = line.substr(0, pos);
        std::string rvalue = line.substr(pos + 1);

        if (i == 0)
        {
            if (lvalue != "date" || rvalue != "exchange_rate")
                return false;
        }
        else
        {
            if ((date = parseDate(lvalue)) < 0 || (rate = parseValue(rvalue, 0, std::numeric_limits<float>::max())) < 0)
                return false;
        }
        if (i != 0)
            dataBase.insert(std::pair<int, float>(date , rate));
    }
    if (dataBase.empty())
        return false;

    return true;
};

void
Bitcoin::executeExchange(std::ifstream &inputFile) const
{
    std::string line;

    for (size_t i = 0; std::getline(inputFile, line); i++)
    {
        size_t pos = line.find(" | ");
        if (pos == std::string::npos)
        {
            CERR("Error: bad input => " << line);
            continue;
        }

        int   date = 0;
        float rate = 0;
        std::string lvalue = line.substr(0, pos);
        std::string rvalue = line.substr(pos + 3);

        if (i == 0)
        {
            if (lvalue != "date" || rvalue != "value")
                CERR("Error: bad input => " << line);
        }
        else
        {
            if ((date = parseDate(lvalue)) < 0 || (rate = parseValue(rvalue, 0, 1000)) < 0)
            {
                if (date == BADINPUT || rate == BADINPUT)
                    CERR("Error: bad input => " << line);
                else if (date == OVERLIMIT)
                    CERR("Error: too large a number.");
                else
                    CERR("Error: not a positive number.");
            }
            else
            {
                std::map<int, float>::const_iterator it = dataBase.upper_bound(date);
                --it;
                COUT(lvalue << " => " << rvalue << " = " << rate * it->second);
            }
        }
    }

};

void
Bitcoin::exchange(const char *fileName) const
{
    std::ifstream inputFile(fileName, std::ios_base::in);

    if (!inputFile.is_open())
        throw (std::runtime_error("Error: Failed to open " + std::string(fileName)));

    executeExchange(inputFile);
    inputFile.close();
};

Bitcoin::~Bitcoin(void)
{
};
