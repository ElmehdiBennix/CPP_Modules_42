
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
        throw (std::runtime_error("Error: Failed to open " DATA_FILE));

    if (!parseCsv(dataFile)) {
        dataFile.close();
        throw (std::runtime_error("Error: Failed to parse " DATA_FILE));
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

bool
Bitcoin::parseDate(const std::string &date)
{
    if (date.length() != 10)
        return (false);

    if (date[5] != '-' || date[8] != '-')
        return (false);

    std::istringstream tokens(date);

    int  year, month, day;
    char dash[2];

    if (!(tokens >> year >> dash[0] >> month >> dash[1] >> day))
        return (false);

    if (dash[0] != '-' || dash[1] != '-')
        return (false);

    if (1 > month || month > 12 || 1 > day || day < 31)
        return (false);

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    // if (month == 2) {
    //     bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    //     if (day > 29 || (day == 29 && !isLeapYear)) {
    //         return false;
    //     }
    // }

    return (true);
};

float
Bitcoin::parseValue(const std::string &date)
{
    float number;
    char  remaining;
    std::istringstream token(date);
    
    if (!(token >> number) || token >> remaining)
        return false;

    if (number < 0 || number > 1000 || number != number || number == std::numeric_limits<float>::infinity() || number == -std::numeric_limits<float>::infinity())
        return false;

    return true;
};

bool
Bitcoin::parseCsv(std::ifstream &dataFile) // dataFile.close();
{
    size_t      i;
    std::string line;

    for (size_t i = 0; std::getline(dataFile, line); i++)
    {
        float rate = 0;
        std::istringstream tokens(line);
    
        for (size_t j = 0; std::getline(tokens, line, ','); j++)
        {
            if (i == 0) 
            {
                switch (j)
                {
                    case 0:
                        if (line != "date")
                            return (false);
                        break;
                    case 1:
                        if (line != "exchange_rate")
                            return (false);
                        break;
                    default:
                        return (false);
                }
            }
            else
            {
                switch (j)
                {
                    case 0:
                        if (!parseDate(line))
                            return (false);
                        break;
                    case 1:
                        if ((rate = parseValue(line)) < 0)
                            return (false);
                        break;
                    default:
                        return (false);
                }
            }
        }
        if (i != 0)
            dataBase.insert(std::pair<std::string, float>(line , rate));
    }

    if (dataBase.empty())
        return false;

    return (true);
};

// bool
// Bitcoin::readFile(std::ifstream& file, dataPoint &savePoint)
// {
    // std::string line;
    // // std::stringstream token;
    // // std::string tok;

    // while (std::getline(file, line, '\n'))
    // {
    //     if (!parseCsv(line))
    //         throw(std::runtime_error("Error : Failed to parse a valid csv format."));
    // }


    // return (true);
// };

void
Bitcoin::exchange(const char *fileName) const
{
    (void)fileName;
    return;
};

Bitcoin::~Bitcoin(void)
{
};
